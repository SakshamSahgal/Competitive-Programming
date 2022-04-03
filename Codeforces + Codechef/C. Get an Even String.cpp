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
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        lli n = s.length();
        lli dp[2][n];
        lli prefix[26][n];
        for(lli i=0;i<26;i++)
            for(lli j=0;j<n;j++)
                prefix[i][j] = -1;

        for(lli i=0;i<n-1;i++)
        {
            lli x = s[i] - 'a';

            for(lli j=0;j<26;j++)
                prefix[j][i+1] = prefix[j][i];

            prefix[x][i+1] = i;
        }

        //array_2d_printer(prefix,26,n);

        dp[0][0] = 0;
        dp[1][0] = 0;
        for(lli i=1;i<n;i++)
        {
            dp[0][i] = max(dp[0][i-1],dp[1][i-1]);
            lli x = s[i] - 'a';
            if(prefix[x][i] == -1)
                dp[1][i] = dp[0][i];
            else
                dp[1][i] = dp[0][prefix[x][i]] + 2;
        }

        //array_2d_printer(dp,2,n);
        lli maxx = -inf;
        for(int i=0;i<n;i++)
            maxx = max(dp[0][i],dp[1][i]);
        cout<<n-maxx<<"\n";
        t--;
    }
    return 0;
}

