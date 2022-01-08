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
using namespace std;

void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,p,k;
        cin>>n>>p>>k;
        string s;
        cin>>s;
        lli x,y;
        cin>>x>>y;
        lli dp[n+1] = {0}; //agar ith index pr land kia hota toh kitne zero encounter hote
        string tt = "-";
        tt += s;
        s = tt;

        //for(int i=1; i<=n; i++)
           // cout<<s[i]<<" ";
        //cout<<"\n";
        for(lli i = n;i>=1;i--)
        {
            if(s[i] == '0')
            {
                if(i+k > n)
                  dp[i] = 1;
                else
                    dp[i] = dp[i+k] + 1;
            }
            else
            {
                if(i+k > n)
                    dp[i] = 0;
                else
                    dp[i] = dp[i+k];
            }
        }
        lli ans = INT_MAX;
        for(lli i=p; i<=n; i++)
            ans = min(ans,((i-p)*y + dp[i]*x));
        cout<<ans<<"\n";
        //array_printer(dp,n);
        t--;
    }
    return 0;
}
