#include<iostream>
#include<cstring>
#include<vector>
#include<iomanip>
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
        lli n;
        cin>>n;
        lli a[n];
        long double z=0;
        long double s=0;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s += a[i];
        }

        z = s/(n*(1.0));
        sort(a,a+n,greater<lli>());
        lli ss=0;
        long double ans = z;
        long double sz=0;
        for(int i=0;i<n-1;i++)
        {
            ss += a[i];
            sz++;
            long double rem_sz = (n - sz);
            long double s1 = ss;
            long double s2 = s - ss;
            long double h = (s1/sz + s2/rem_sz)/2.0;
            //cout<<(long double)h<<"\n";
            ans = max(ans,h);
        }
        cout<<setprecision(20)<<ans<<"\n";
        t--;
    }
    return 0;
}
