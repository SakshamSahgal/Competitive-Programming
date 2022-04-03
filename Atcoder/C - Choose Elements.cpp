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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

        lli n,k;
        cin>>n>>k;
        lli dp[4][n];
        lli x[2][n];

        for(lli i=0; i<n; i++)
            cin>>x[0][i];
        for(lli i=0; i<n; i++)
            cin>>x[1][i];

        for(int i=0;i<4;i++)
            for(int j=0;j<n;j++)
                dp[i][j] = 0;

        for(lli i=n-1; i>=1; i--)
        {
            if(i == n-1)
            {
                if ( abs(x[0][i-1] - x[0][i] ) <= k)
                    dp[0][i] = 1;
                else
                    dp[0][i] = -1;

                if ( abs(x[0][i-1] - x[1][i] ) <= k)
                    dp[1][i] = 1;
                else
                    dp[1][i] = -1;

                if ( abs(x[1][i-1] - x[0][i] ) <= k)
                    dp[2][i] = 1;
                else
                    dp[2][i] = -1;

                if ( abs(x[1][i-1] - x[1][i] ) <= k)
                    dp[3][i] = 1;
                else
                    dp[3][i] = -1;
            }
            else
            {
                if ( (abs(x[0][i-1] - x[0][i] ) <= k) && (dp[0][i+1] == 1 || dp[1][i+1] == 1) )
                    dp[0][i] = 1;
                else
                    dp[0][i] = -1;

                if ( (abs(x[0][i-1] - x[1][i] ) <= k) && (dp[2][i+1] == 1 || dp[3][i+1] == 1) )
                    dp[1][i] = 1;
                else
                    dp[1][i] = -1;

                if ( (abs(x[1][i-1] - x[0][i] ) <= k) && (dp[0][i+1] == 1 || dp[1][i+1] == 1) )
                    dp[2][i] = 1;
                else
                    dp[2][i] = -1;


                if ( (abs(x[1][i-1] - x[1][i] ) <= k) && (dp[2][i+1] == 1 || dp[3][i+1] == 1) )
                    dp[3][i] = 1;
                else
                    dp[3][i] = -1;
            }
        }

        bool found = 0;

        //array_2d_printer(dp,4,n);

        for(int i=0;i<4;i++)
        {
            if( dp[i][1] == 1)
            {
                found = 1;
                break;
            }
        }

        if(found)
        {
            cout<<"Yes\n";
            /*
            for(int i=1;i<n;i++)
            {
                if(i == 1)
                {
                    if(dp[0][i] == 1)
                        cout<<x[0][0]<<" "<<x[0][1]<<" ";
                    else if(dp[1][i] == 1)
                        cout<<x[0][0]<<" "<<x[1][1]<<" ";
                    else if(dp[2][i] == 1)
                        cout<<x[1][0]<<" "<<x[0][1]<<" ";
                    else if(dp[3][i] == 1)
                        cout<<x[1][0]<<" "<<x[1][1]<<" ";
                }
                else
                {
                    if(dp[0][i] == 1 || dp[2][i] == 1)
                        cout<<x[0][i]<<" ";
                    else
                        cout<<x[1][i]<<" ";
                }
            } */
        }
        else
            cout<<"No\n";

    return 0;
}

