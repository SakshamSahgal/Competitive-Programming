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
    lli n,m;
    cin>>n>>m;
    char x[n][m];
    set<lli> y;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>x[i][j];
            if(i != 0 && j != 0 && x[i-1][j] == 'X' && x[i][j-1] == 'X')
                y.insert(j);
        }
    }

    lli q;
    cin>>q;

    while(q--)
    {
        lli x1,x2;
        cin>>x1>>x2;
        x1--;
        x2--;
        if(x1 == x2)
            cout<<"YES\n";
        else
        {
            auto ptr = y.lower_bound(x1+1);
            if(ptr != y.end() && (*ptr) <= x2)
                cout<<"NO\n";
            else
                cout<<"YES\n";
        }
    }

    return 0;
}
