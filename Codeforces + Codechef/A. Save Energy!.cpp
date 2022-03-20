#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;



int main()
{
    //GO_FAST
    lli k,d,t;
    cin>>k>>d>>t;
    long double ans;
    if(d <= k)
    {
        if(k%d == 0)
            ans = t;
        else
        {
            lli len = ceil( (k*1.0)/(d*1.0) )*d;
            lli ton = k;
            lli toff = d - k%d;
            lli c;

            if( (2*t) < (2*k + d - k%d))
                c = 0;
            else
                c = (2*t)/(2*k + d - k%d);

            long double rem = t - c*(((2*k + d - k%d)*1.0)/2.0);

            //cout<<"len = "<<len<<" ton = "<<ton<<" toff = "<<toff<<" complete interval = "<<c<<" rem = "<<rem<<"\n";

            if(rem <= k)
                ans = c*len + rem;
            else
                ans = c*len + k + 2*(rem-k);
        }

    }
    else
    {
        lli len = d;
        lli ton = k;
        lli toff = d - k;
        lli c;

        if((2*t) < (d+k))
            c = 0;
        else
            c = (2*t)/(d+k);

        long double rem = t - ((c*((k+d)*1.0))/2.0);

        //cout<<"len = "<<len<<" ton = "<<ton<<" toff = "<<toff<<" complete interval = "<<c<<" rem = "<<rem<<"\n";

        if(rem <= k)
            ans = c*len + rem;
        else
            ans = c*len + k + 2*(rem-k);
    }
    cout<<setprecision(20)<<ans<<"\n";
    return 0;
}

