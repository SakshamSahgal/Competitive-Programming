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
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    lli a[n];

    for(int i=0;i<n;i++)
      cin>>a[i];

    lli m1=inf;
    lli m2=inf;
    lli m3=inf;
    for(int i=0;i<n-1;i++)
    {
        lli mx = max(a[i],a[i+1]);
        lli mn = min(a[i],a[i+1]);
        lli mv;
        if( mx >= 2*mn )
        {
            lli z = mx - 2*mn;
            mv = (z%2) ? mn + z/2 + 1 : mn + z/2 ;
        }
        else
        {
            lli z = mx - mn;
            lli h =  2*(mx - 2*z);
            mv = (h%3) ? z + h/3 + 1 : z + h/3;
        }
        m1 = min(m1,mv);
    }

    for(int i=0;i<n-2;i++)
    {
        lli mx = max(a[i],a[i+2]);
        lli mn = min(a[i],a[i+2]);
        lli mv;
        lli rem = (mx-mn);
        mv = ( rem%2 ) ? mn + rem/2 + 1 : mn + rem/2;
        m2 = min(m2,mv);
    }

    vector<lli> moves;

    for(int i=0;i<n;i++)
    {
        lli mv = (a[i]%2) ? a[i]/2 + 1 : a[i]/2;
        moves.push_back(mv);
    }

    sort(moves.begin(),moves.end());

    m3 = moves[0] + moves[1];

    cout<<min(m1,min(m2,m3))<<"\n";

    return 0;
}
