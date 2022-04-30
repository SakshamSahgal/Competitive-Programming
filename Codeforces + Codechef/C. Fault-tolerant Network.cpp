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


lli mini(lli a[],lli n,lli x)
{
    lli z = inf;

    for(int i=0;i<n;i++)
        z = min(z,abs(a[i]-x));

    return z;
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
        lli n;
        cin>>n;
        lli a[n];
        lli b[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            cin>>b[i];

        lli ul = mini(b,n,a[0]);
        lli ur = mini(b,n,a[n-1]);
        lli ll = mini(a,n,b[0]);
        lli lr = mini(a,n,b[n-1]);
        lli ans[7];

        ans[0] = abs(a[0] - b[n-1]) + abs(b[0] - a[n-1]);
        ans[1] = abs(a[0] - b[0]) + abs(a[n-1] - b[n-1]);
        ans[2] = abs(a[0] - b[0]) + ur + lr;
        ans[3] = abs(a[n-1] - b[n-1]) + ul + ll;
        ans[4] = abs(a[0] - b[n-1]) + ur + ll;
        ans[5] = abs(a[n-1] - b[0]) + ul + lr;
        ans[6] = ul + ur + ll + lr;

        lli mini = inf;

        for(int i=0;i<7;i++)
            mini = min(mini,ans[i]);

        cout<<mini<<"\n";
        t--;
    }
    return 0;
}
