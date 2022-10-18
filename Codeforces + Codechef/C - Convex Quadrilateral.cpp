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
    ld ax,ay,bx,by,cx,cy,dx,dy;
    cin>>ax>>ay;
    cin>>bx>>by;
    cin>>cx>>cy;
    cin>>dx>>dy;
    if(bx == dx && cx <=bx)
        cout<<"No\n";
    else if(ax == cx && bx <= ax)
        cout<<"No\n";
    else
    {
        ld m1 = abs((ay - cy)/(ax-cx));
        ld m2 = ()/();
    }
    return 0;
}

