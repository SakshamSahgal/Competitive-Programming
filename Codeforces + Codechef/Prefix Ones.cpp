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
        string s;
        cin>>s;
        lli dp[n] = {0};
        lli fz=-1;
        for(int i=n-1; i>=0; i--)
        {

            if(s[i] == '1')
            {
                if(i == n-1)
                    dp[i] = (s[i] == '1');
                else
                    dp[i] = (s[i] == '1') + dp[i+1];
            }
            else
            {
                 fz = i;
                 dp[i] = 0;
            }
        }

        if(fz == -1)
            cout<<n<<"\n";
        else
        {
            lli ans=0;
            for(int i=fz;i<n;i++)
                ans = max(ans,dp[i]);
            ans += fz;
            cout<<ans<<"\n";
        }
        t--;
    }
    return 0;
}

