#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
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
    GO_FAST
    lli k,d,t;
    cin>>k>>d>>t;
    if( d <= k)
    {
        if(k%d == 0)
            cout<<t<<"\n";
        else
        {
            lli I = ceil( ( ( (long double)k / (long double) d ) ) )* d;
            cout<<" one Interval size = "<<I<<"\n";
            lli ci;

            lli ton = k;
            lli toff = (d - k%d);

            if(   (2*t) < (2*ton + toff) )
                ci = 0;
            else if( (2*t) == (2*ton + toff) )
                ci = 1;
            else
                ci = (2*t)/(2*ton + toff);

            long double tim = ci*I;
            cout<<"Complete intervals = "<<ci<<" time till now = "<<tim<<"\n";
            long double extra=0;

            if( 2*(I*k + k) + I*(toff) > 2*t  ) //therefore only t_on
            {
                cout<<"Only k se \n";
                extra = ((2*t - ci*toff - 2*ci*k)*1.0)/2.0;
                cout<<"Extra = "<<extra<<"\n";
            }
            else
                extra = 2*t - 2*k*(ci+1) - ci*toff;
            tim += extra;

            cout<<"time = ";
            cout<<setprecision(20)<<tim<<"\n";
        }
    }
    else
    {
        lli I = d;
        cout<<" one Interval size = "<<I<<"\n";
        lli ci;

        lli ton = k;
        lli toff = (d - k);
        cout<<" time on = "<<ton<<" time off = "<<toff<<"\n";
        if(2*t < (k+d))
            ci = 0;
        else if(2*t == (k+d))
            ci = 1;
        else
            ci = (2*t)/(k+d);

        long double tim = ci*I;
        cout<<"Complete intervals = "<<ci<<" time till now = "<<tim<<"\n";
        long double extra=0;

        if( 2*k*(ci + 1) + ci*toff > 2*t )
        {
            cout<<"Only k se \n";
            extra = ((2*t - 2*ci*k - ci*toff)*1.0)/2.0;
            cout<<"Extra = "<<extra<<"\n";
        }
        else
        {
            extra = 2*t - ci*k - 2*k - ci*d;
            cout<<"extra = "<<extra<<"\n";
        }



        tim += extra;

        cout<<"time = ";
        cout<<setprecision(20)<<tim<<"\n";

    }
    return 0;
}

