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
        lli n,m;
        cin>>n>>m;
        lli a[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cin>>a[i][j];
        }

        if( (n+m-1)%2 == 0 )
        {
            lli dp_mini[n][m];
            lli dp_maxx[n][m];

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(i==0 && j==0)
                    {
                        dp_mini[i][j] = a[i][j];
                        dp_maxx[i][j] = a[i][j];
                    }
                    else
                    {
                        if(i==0)
                        {
                            dp_mini[i][j] = a[i][j] + dp_mini[i][j-1];
                            dp_maxx[i][j] = a[i][j] + dp_maxx[i][j-1];
                        }
                        else if(j == 0)
                        {
                            dp_mini[i][j] = a[i][j] + dp_mini[i-1][j];
                            dp_maxx[i][j] = a[i][j] + dp_maxx[i-1][j];
                        }
                        else
                        {
                            dp_mini[i][j] = a[i][j] + min(dp_mini[i-1][j],dp_mini[i][j-1]);
                            dp_maxx[i][j] = a[i][j] + max(dp_maxx[i-1][j],dp_maxx[i][j-1]);
                        }
                    }
                }
            }

            //array_2d_printer(dp_mini,n,m);
            //array_2d_printer(dp_maxx,n,m);

            if(dp_mini[n-1][m-1] <= 0 && dp_maxx[n-1][m-1] >= 0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
            cout<<"NO\n";
        t--;
    }
    return 0;
}
