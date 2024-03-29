#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
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

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli t;
    cin>>t;
    for(lli i=1; i<=t; i++)
    {
        lli n,m;
        cin>>n>>m;
        ld a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        sort(a,a+n);
        ld ans=0;

        for(int i=0; i<m-1; i++)
            ans += a[n-1-i];

        lli len = n-m+1;

        if(len%2)
            ans += a[len/2];
        else
            ans += (a[len/2] + a[len/2 - 1])/2.0;

        cout<<setprecision(20)<<"Case #"<<i<<": "<<ans<<"\n";
    }




    return 0;
}
