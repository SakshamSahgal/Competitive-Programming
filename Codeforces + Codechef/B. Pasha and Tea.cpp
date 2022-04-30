#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
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
    //freopen("myout.txt", "w", stdout);

    long double n,w;
    cin>>n>>w;
    lli z = (lli)2*n;
    long double a[z];
    for(int i=0; i<z; i++)
        cin>>a[i];
    sort(a,a+z);
    //array_printer(a,z);
    long double f = min( ((a[z/2]*1.0)/2.0) , (long double)a[0] );
    long double h = w/(3.0*n);
    long double x = min(f,h);
    //cout<<"f = "<<f<<" h = "<<h<<"\n";
    cout<<setprecision(20)<<(3.0*n*x)<<"\n";

    return 0;
}
