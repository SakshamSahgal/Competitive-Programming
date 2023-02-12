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
typedef pair<lli,lli> pll;


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        if(n%2 == 0)
        {
            cout<<"YES\n";
            for(int i=0; i<n; i++)
            {
                if(i%2)
                    cout<<"-1 ";
                else
                    cout<<"1 ";
            }
            cout<<"\n";
        }
        else
        {
            if(n == 3)
                cout<<"NO\n";
            else
            {
                cout<<"YES\n";
                lli x = (3-n)/2;
                for(int i=0; i<n; i++)
                {
                    lli z;
                    if(i%2)
                        z = 1 - x;
                    else
                        z = x;
                    cout<<z<<" ";
                }
                cout<<"\n";
            }
        }
        t--;
    }
    return 0;
}

