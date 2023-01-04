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


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,x,y;
        cin>>n>>x>>y;
        lli a[n];
        lli max_ele = -inf;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            max_ele = max(max_ele,a[i]);
        }

        lli moves=0;
        lli moves2= (max_ele/y + (max_ele%y != 0));
        for(int i=n-1;i>=0;i--)
        {
            lli rem = a[i] - moves*y;
            if(rem > 0)
                moves += (rem/x + (rem%x != 0));
        }
        lli ans = min(moves2,moves);
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

