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
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli a[n][m];

        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                cin>>a[i][j];
        lli c=0;
        for(lli i=0; i<n; i++)
        {
            for(lli j=0; j<m; j++)
            {
                lli ver_cap = min(i,(n-i-1));
                lli horz_cap = min(j,(m-j-1));

                for(lli k=0;k<=min(ver_cap,horz_cap);k++)
                {
                    if(a[i-k][j] == a[i+k][j] && a[i][j-k] == a[i][j+k])
                        c++;
                    else
                        break;
                }
            }
        }

        cout<<c<<"\n";

        t--;
    }
    return 0;
}

