#include<bits/stdc++.h>
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
typedef pair<lli,lli> pll;

lli unset_bit(lli n,lli r)
{
    lli bt = 1;
    lli ans = n;
    if( ((n>>r)&(bt)) ) //if that bit is set
        ans = ans & (~(bt<<r));
    return ans;
}

bool is_set(lli n,lli r)
{
    lli bt = 1;
    lli ans = n;
    return ((n>>r)&(bt));
}

lli set_bit(lli n,lli r)
{
    lli bt = 1;
    lli ans = n;
    if( ((bt<<r)&(n)) == 0) //if that bit is unset
        ans = ((bt<<r)^(n));
    return ans;
}


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli no = 0;
    no = set_bit(no,0);
    no = set_bit(no,1);
    no = set_bit(no,22);
    cout<<no<<"\n";
    no = unset_bit(no,22);
    cout<<no<<"\n";
    cout<<is_set(no,22)<<"\n";
    cout<<is_set(no,1)<<"\n";

    pll a = {2,3};
    pll b = {3,2};
    cout<<(a < b)<<"\n";

    return 0;
}

