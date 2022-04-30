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

lli val(lli x1,lli y1,lli i,lli j)
{
    if(x1%2 != y1%2)
    {
        if(i%2 == j%2)
            return 2;
        else
            return 1;
    }
    else
    {
        if(i%2 == j%2)
            return 1;
        else
            return 2;
    }
}

bool is_poss(lli i,lli j,lli n,lli m)
{
    if(i < 0 || j < 0 || i >= n || j >= m)
        return 0;
    else
        return 1;
}

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
        x1--;
        y1--;
        x2--;
        y2--;
        lli x[n][m];
        x[x1][y1] = 1;

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
                x[i][j] = val(x1,y1,i,j);
        }
        x[x2][y2] = 2;
        //array_2d_printer(x,n,m);

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if( !(i == x1 && j == y1) && !(i == x2 && j == y2) )
                {
                    if( is_poss(i-1,j,n,m) && x[i-1][j] == x[i][j]) //uppar
                        x[i][j] = 3;
                    else if( is_poss(i,j-1,n,m) && x[i][j-1] == x[i][j]) //left
                        x[i][j] = 3;
                    else if( is_poss(i+1,j,n,m) && x[i+1][j] == x[i][j]) //neeche
                        x[i][j] = 3;
                    else if( is_poss(i,j+1,n,m) && x[i][j+1] == x[i][j]) //right
                        x[i][j] = 3;
                }
            }
        }

        //array_2d_printer(x,n,m);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
                cout<<x[i][j]<<" ";
            cout<<"\n";
        }
        t--;
    }
    return 0;
}
