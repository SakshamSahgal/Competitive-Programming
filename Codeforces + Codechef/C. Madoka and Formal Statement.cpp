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
        vector<lli> a(n);
        vector<lli> b(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        for(int i=0; i<n; i++)
            cin>>b[i];

        if(a == b)
            cout<<"YES\n";
        else
        {
            bool all_less = 1;
            for(int i=0; i<n; i++)
            {
                if(a[i] > b[i])
                {
                    all_less = 0;
                    break;
                }
            }

            if(!all_less)
                cout<<"NO\n";
            else
            {
                bool fail=0;
                for(int i=0; i<n-1; i++)
                {
                    if(a[i] != b[i])
                    {
                        if(b[i] - b[i+1] > 1)
                        {
                            fail = 1;
                            break;
                        }
                    }
                }

                if(a[n-1] != b[n-1] && b[n-1] - b[0] > 1)
                    fail = 1;

                if(fail)
                    cout<<"NO\n";
                else
                    cout<<"YES\n";
            }
        }
        t--;
    }
    return 0;
}
