#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<complex>
#include<cmath>
#include<iomanip>
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


typedef complex<double> point;
#define x real()
#define y imag()

point rotate(point P, point Q, double theta)
{
    return (P - Q) * (polar(1.0, theta)) + Q;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    long double xx,yy,d;
    cin>>xx>>yy>>d;
    d = (d*3.14159265358)/180;
    point a(xx,yy);
    point b(0.0,0.0);
    point r = rotate(a, b, d);
    std::cout << std::setprecision(20) << (r.x) << " ";
    std::cout << std::setprecision(20) << (r.y) << " ";
    return 0;
}
