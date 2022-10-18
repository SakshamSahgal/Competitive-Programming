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


void printer(vector<vector<pair<int,int>>> &x)
{
    for(int i=0; i<x.size(); i++)
    {
        for(int j=0; j<x[i].size(); j++)
            cout<<"["<<x[i][j].first<<" "<<x[i][j].second<<"] ";
        cout<<"\n";
    }
}

int maximalRectangle(vector<vector<int> > &A)
{
    int n = A.size();
    int m = A[0].size();
    vector<vector<pair<int,int>>> dp(n,vector<pair<int,int>>(m));
    for(int i=0; i<n; i++)
    {
        if(A[i][0] == 1)
        {
            if(i == 0)
                dp[i][0] = {1,1};
            else
                dp[i][0] = {1,dp[i-1][0].second + 1};
        }
        else
            dp[i][0] = {0,0};
    }

    for(int j=0; j<m; j++)
    {
        if(A[0][j] == 1)
        {
            if(j == 0)
                dp[0][j] = {1,1};
            else
                dp[0][j] = {dp[0][j-1].first + 1,1};
        }
        else
            dp[0][j] = {0,0};
    }

    //printer(dp);
    int ans = -1e9;

    for(int i=1; i<n; i++)
    {
        for(int j=1; j<m; j++)
        {
            if(A[i][j] == 1)
            {
                int w1 = dp[i][j-1].first;
                int h1 = dp[i][j-1].second;
                int w2 = dp[i-1][j].first;
                int h2 = dp[i-1][j].second;
                int w3 = dp[i-1][j-1].first;
                int h3 = dp[i-1][j-1].second;
                if(w1 > w3 && h2 > h3)
                {
                    if((1+w1)*h1 > (1+h2)*w2)
                        dp[i][j] = {1+w1,h1};
                    else
                        dp[i][j] = {w2,1+h2};
                }
                else if(w1 > w3)
                {
                    if(1+h2 < h1)
                        dp[i][j] = {1+w1,1+h2};
                    else
                    {
                        if((1+w1)*h1 > (1+h2)*w2)
                            dp[i][j] = {1+w1,h1};
                        else
                            dp[i][j] = {w2,1+h2};
                    }
                }
                else if(h2 > h3)
                {
                    if(1+w1 < w2)
                        dp[i][j] = {1+w1,1+h2};
                    else
                    {
                        if((1+w1)*h1 > (1+h2)*w2)
                            dp[i][j] = {1+w1,h1};
                        else
                            dp[i][j] = {w2,1+h2};
                    }

                }
                else
                    dp[i][j] = {1+w1,1+h2};
            }
            else
                dp[i][j] = {0,0};

        }
    }

    printer(dp);
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
            ans = max(ans,(dp[i][j].first*dp[i][j].second));
    }
    return ans;
}





int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    vector<vector<int>> A =
    {
        {1, 1, 0, 0},
        {0, 0, 0, 0},
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 1, 1},
        {1, 0, 0, 1}
    };
    cout<<maximalRectangle(A);
    return 0;
}

