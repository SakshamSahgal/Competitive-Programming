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

/*
void array_printer(lli a[],lli n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
} */

int main()
{
    //GO_FAST
    string s;
    cin>>s;
    lli n = s.length();
    lli dp[n] = {0};
    lli ans = 0;
    lli c;
    s[n-1] == ')' ? c = 1:c=0;
    for(int i=n-2; i>=0; i--)
    {
        if(s[i] == ')')//closed
        {
            dp[i] = dp[i+1];
            c++;
        }
        else
        {
            if(c == 0) //nhi mila
                dp[i] = dp[i+1];
            else
            {
                c--;
                dp[i] = dp[i+1] + 2;
            }
        }
    }

   // array_printer(dp,n);
    for(int i=0;i<n;i++)
        ans = max(ans,dp[i]);
    cout<<ans<<"\n";
    return 0;
}
