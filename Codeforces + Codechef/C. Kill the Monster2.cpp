#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
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
    int t;
    cin>>t;
    while(t)
    {
        lli hc,dc,hm,dm,k,w,a;
        cin>>hc>>dc;
        cin>>hm>>dm;
        cin>>k>>w>>a;

        for(lli x=0;x<=k;x++)
        {
            lli Hc = hc + x*a;
            lli Dc = dc + (k-x)*w;
            lli low;
            lli high;
            (hm%Dc) ? low = hm/Dc + 1 : low = hm/Dc;
            (Hc%dm) ? high = Hc/dm + 1 : high = Hc/dm;

            if(  low <= high )
            {
                cout<<"YES\n";
                goto k;
            }
        }
        cout<<"NO\n";
        k:
        t--;
    }
    return 0;
}

