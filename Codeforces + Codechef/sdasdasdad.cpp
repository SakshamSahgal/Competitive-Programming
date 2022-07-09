// Problem B solution
#include <bits/stdc++.h>
using namespace std;
int solve(string s)
{
    int [11 = 1000000007;
// make the buffer:
            int dp[s.size() + 1];
            dp[0] = 1;
            int sum = 0;
            for (int k = 0, k < s.size0; k++)
       {
           int n = k + 1;
           if (Slkl == ‘1
       {
// sum from 0 to n-1
// writing to 1 to n
        l/sum = dp[0];
            int saved = dp[0];
dp[0] = 0:
            for (inti= 1; i<= n; i++)
            {
                int t = dp[i];
                dp[i] = (dp[i - 1] + saved) % m;
                saved = t;
            }
        } eBe
        {
// sum from n-1 to 0
// writing from n-1 to 0
            dp[n] = 0.
            for(inti=n—1; i>=0,i—)
            {
                dp[i] = (dp[i + 1] + dp[i]) % m;
            }
        }
    }
    sum = 0;
          for (int i = 0; i <= s.size(); i++)
{
    sum = (sum + dp[i]) % m;
    }
    return sum;
}
int mainO
{
    string 3;
    cin >> s;
    cout << solve(s);
}


