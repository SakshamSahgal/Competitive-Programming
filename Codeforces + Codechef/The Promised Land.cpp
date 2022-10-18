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

//remember to use endl instead of \n for interactive problems.

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m,x,y,s;
        cin>>n>>m;
        cin>>x>>y>>s;
        vector<lli> r(x+2);
        vector<lli> c(y+2);
        r[0] = 0;
        c[0] = 0;
        r[x+1] = n+1;
        c[y+1] = m+1;
        for(int i=1;i<=x;i++)
            cin>>r[i];
        for(int i=1;i<=y;i++)
            cin>>c[i];

        lli sum=0;
        lli ans=0;
        for(int i=0;i<y+1;i++)
            sum += (c[i+1] - c[i] - 1)/s;

        //cout<<sum<<"\n";

        for(int i=0;i<x+1;i++)
            ans += ((r[i+1] - r[i] - 1)/s)*sum;
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
