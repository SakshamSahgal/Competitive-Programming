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
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
                cin>>a[i][j];
        lli mxi=0;
        lli mxj=0;
        lli mx=-inf;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(a[i][j] > mx)
                {
                    mx = a[i][j];
                    mxi = i;
                    mxj = j;
                }
            }
        }

        lli a1 = ( abs(mxi) + 1 )*(abs(mxj) + 1 );
        lli a2 = (abs(mxi) + 1)*(abs(mxj - (m-1)) + 1);
        lli a3 = (abs(n-1 - mxi)+1)*(abs(mxj)+1);
        lli a4 = (abs(n-1 - mxi)+1)*(abs(mxj - (m-1))+1);
        cout<<max(max(a1,a2),max(a3,a4))<<"\n";
        t--;
    }
    return 0;
}
