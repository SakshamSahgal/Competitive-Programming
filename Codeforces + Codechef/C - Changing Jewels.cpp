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
lli n,x,y;
lli ans=0;
void jw(lli level,char c,lli k)
{
    //cout<<"at = "<<c<<" level = "<<level<<" k = "<<k<<"\n";
    if(level == 1)
    {
        if(c == 'R')
            return;
        else
          ans += k;
        return;
    }
    if(c == 'R')
    {
        jw(level-1,'R',k);
        jw(level,'B',(k*x));
    }
    else
    {
        jw(level-1,'R',k);
        jw(level-1,'B',(k*y));
    }
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    cin>>n>>x>>y;
    jw(n,'R',1);
    cout<<ans<<"\n";
    return 0;
}
