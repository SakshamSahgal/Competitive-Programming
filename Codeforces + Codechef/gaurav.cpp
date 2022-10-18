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

//remember to use endl instead of \n for interactive problems.




int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    map<lli,lli> z;
    z[0] = 0;
    lli n;
    cin>>n;
    for(lli i=1;i<=n;i++)
    {
        lli a = (z[(i/2)] > i/2) ? z[(i/2)] : i/2;
        lli b = (z[(i/3)] > i/3) ? z[(i/3)] : i/3;
        lli c = (z[(i/4)] > i/4) ? z[(i/4)] : i/4;
        z[i] = a + b + c;
        //cout<<"i = "<<i<<" val = "<<(a+b+c)<<"\n";
    }
    cout<<z[n]<<" ";
    return 0;
}

