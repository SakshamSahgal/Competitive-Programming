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

    lli n,m;
    cin>>n>>m;
    lli x[n+1][n+1];

    for(int i=0; i<=n; i++)
        for(int j=0; j<=n; j++)
            x[i][j] = 1;

    for(int i=1; i<=m; i++)
    {
        lli a,b;
        cin>>a>>b;
        x[a][b] = 0;
        x[b][a] = 0;
    }


    for(lli i=1; i<=n; i++)
    {
        bool all_one = 1;
        for(int j=1; j<=n; j++)
        {
            if(x[i][j] == 0)
            {
                all_one = 0;
                break;
            }
        }

        if(all_one)
        {
            cout<<n-1<<"\n";
            lli fr = i;
            for(int k=1; k<=n; k++)
            {
                if(fr != k)
                    cout<<fr<<" "<<k<<"\n";
            }
            break;
        }
    }

    return 0;
}

