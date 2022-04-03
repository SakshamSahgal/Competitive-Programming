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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);    int t;

        lli n;
        cin>>n;
        lli a[n];
        lli sum=0;
        for(lli i=0;i<n;i++)
        {
            cin>>a[i];
            sum += a[i];
        }
        //cout<<sum<<"\n";
        sort(a,a+n);
        lli m;
        cin>>m;
        lli b[m];
        for(lli i=0;i<m;i++)
        {
           cin>>b[i];
           cout<<(sum - a[(n - b[i])])<<"\n";
        }

    return 0;
}

