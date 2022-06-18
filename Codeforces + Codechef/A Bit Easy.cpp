#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_map>
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
        lli n,k;
        cin>>n>>k;
        lli a[n];
        lli y[n];

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            y[i] = k - a[i];
        }


        unordered_map<lli,lli> f;
        lli ans=0;
        for(lli i=n-1; i>=0; i--)
        {
            lli to_search=0;
            if( y[i] >= 0 )
            {
                to_search = a[i]^y[i];
                ans += f[to_search];
            }

            f[a[i]]++;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
