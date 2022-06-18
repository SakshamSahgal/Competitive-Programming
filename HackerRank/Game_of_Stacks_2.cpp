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

lli maxx_sum(lli sum,lli mx_sum,lli ps[],lli m)
{
    if(sum + ps[0] > mx_sum)
        return 0;

    lli l=0;
    lli h=m-1;
    lli ans=-1;
    while(l <= h)
    {
        lli mid = (l+h)/2;
        if(sum + ps[mid] <= mx_sum)
        {
            l = mid+1;
            ans = mid+1;
        }
        else
            h = mid-1;
    }

    return ans;
}
int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m,mx_sum=0;
        cin>>n>>m>>mx_sum;
        lli a[n];
        lli b[m];

        for(int i=0; i<n; i++)
            cin>>a[i];
        lli ps[m];
        for(int i=0; i<m; i++)
        {
            cin>>b[i];
            ps[i] = (i == 0) ? b[i] : (b[i] + ps[i-1]);
        }

        lli i=-1;
        lli s=0;
        lli ans = maxx_sum(s,mx_sum,ps,m);
       // cout<<" i = "<<i<<" bc = "<<ans<<"\n";

        while(i + 1 < n && (s + a[i+1] <= mx_sum))
        {
            s += a[i+1];
            i++;
            lli bc = maxx_sum(s,mx_sum,ps,m);
            //cout<<" i = "<<i<<" bc = "<<bc<<"\n";
            ans = max(ans,i+1+bc);
        }
        cout<<ans<<"\n";
        t--;
    }

    return 0;
}
