#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.




int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli tn;
        cin>>tn;
        lli n;
        if(tn == 1)
            cout<<0<<"\n";
        else if( (tn-2)%5 == 0 )
        {
            n = (tn-2)/5 + 1;
            cout<<(2*n-1)<<"\n";
        }
        else if( (tn-3)%5 == 0 )
        {
            n = (tn-3)/5 + 1;
            cout<<(2*n-1)<<"\n";
        }
        else if( (tn-4)%5 == 0 )
        {
            n = (tn-4)/5 + 1;
            cout<<(2*n-1)<<"\n";
        }
        else if( (tn-5)%5 == 0 )
        {
             n = (tn-5)/5 + 1;
            cout<<(2*n)<<"\n";
        }
        else
        {
            n = (tn-6)/5 + 1;
            cout<<(2*n)<<"\n";
        }
        t--;
    }
    return 0;
}

