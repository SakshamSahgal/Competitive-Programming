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
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        lli inv[n];
        for(int i=0;i<n;i++)
        {
            if(i == 0)
                inv[i] = 0;
            else
            {
                if(s[i-1] != s[i])
                    inv[i] = inv[i-1] + 1;
                else
                    inv[i] = inv[i-1];
            }
        }
        lli ans=1e9;
        for(int i=0;i<n;i++)
        {
            lli j = i+k-1;
            if(j >= n)
                break;
            else
            {
                lli z = inv[j] - inv[i];
                if(s[j] == '0')
                    z++;
                ans = min(ans,z);
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

