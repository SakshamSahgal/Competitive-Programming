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

lli ans(lli l_rem,lli a_rem,lli b_rem,lli c,lli n,lli a,lli b)
{
    if(a_rem == 0 && b_rem == 0)
        return c;

    lli c1=inf;
    lli c2=inf;
    if(a_rem)
    {
        if(l_rem >= a)
            c1 = ans(l_rem-a,a_rem-1,b_rem,c,n,a,b);
        else
            c1 = ans(n-a,a_rem-1,b_rem,c+1,n,a,b);
    }
    if(b_rem)
    {
        if(l_rem >= b)
            c2 = ans(l_rem-b,a_rem,b_rem-1,c,n,a,b);
        else
            c2 = ans(n-b,a_rem,b_rem-1,c+1,n,a,b);
    }
    return min(c1,c2);
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,a,b;
    cin>>n>>a>>b;
    cout<<ans(n,4,2,1,n,a,b);
    return 0;
}
