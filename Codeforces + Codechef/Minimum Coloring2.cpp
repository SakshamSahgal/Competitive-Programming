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
//remember a 2d array cannot be initialized by setting a[n][m] = {0}; prefer vectors over arrays



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
        lli x1,y1,x2,y2;
        cin>>x1>>y1;
        cin>>x2>>y2;
        vector<vector<lli>> a(n,vector<lli>(m,0));
        x1--;
        y1--;
        x2--;
        y2--;
        a[x1][y1] = 1;
        a[x2][y2] = 2;

        if( (x1+y1)%2 != (x2+y2)%2 )
        {
            lli val[2];
            val[(x1+y1)%2] = 1;
            val[(x2+y2)%2] = 2;

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                    a[i][j] = val[(i+j)%2];
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if((i+j)%2 == (x1+y1)%2)
                        a[i][j] = 1;
                    else
                        a[i][j] = 3;
                }
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                cout<<a[i][j]<<" ";
            cout<<"\n";
        }

        t--;
    }
    return 0;
}

