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
    lli n,q;
    cin>>n>>q;

    lli a[n+1];
    lli loc[n+1];
    for(int i=1; i<=n; i++)
    {
        a[i] = i;
        loc[i] = i;
    }

    while(q--)
    {
        lli x;
        cin>>x;

        if(loc[x] == n)
        {
            lli z = a[loc[x]];
            lli y = a[loc[x]-1];
            swap(a[loc[x]],a[loc[x]-1]);
            swap(loc[z],loc[y]);
        }
        else
        {
            lli z = a[loc[x]];
            lli y = a[loc[x]+1];
            swap(a[loc[x]],a[loc[x]+1]);
            swap(loc[z],loc[y]);
        }
    }

    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";



    return 0;
}
