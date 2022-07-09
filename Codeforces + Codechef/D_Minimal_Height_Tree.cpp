#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
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

pair<lli,lli> acc(lli st,lli a[],lli n)
{
    lli l=st;
    lli r=st;
    while(r+1<n && a[r] < a[r+1])
        r++;
    pair<lli,lli> ans = {l,r};
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
        lli n;
        cin>>n;
        lli a[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        lli i=1;
        lli c=0;
        int prev_level=0;
        lli level=1;
        lli this_level=0;
        while( i < n )
        {
          pair<lli,lli> lr = acc(i,a,n);
          this_level += lr.second-lr.first+1;
          //cout<<" l = "<<lr.first<<" r = "<<lr.second<<"\n";
          level--;
          c = prev_level+1;

          if (level == 0)
          {
              prev_level++;
              level = this_level;
              this_level=0;
          }
          i = lr.second + 1;
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}