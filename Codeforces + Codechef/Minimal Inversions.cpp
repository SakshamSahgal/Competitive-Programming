#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including

#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}

using namespace std;
using namespace __gnu_pbds;

typedef tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<lli,null_type,less_equal<lli>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//accending order -> less<int>
//decending order -> greater<int>
//if you want character ordered set change the int to char


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        ordered_multiset x;
        for(int i=0;i<n;i++)
            cin>>a[i];

        lli b[n] = {0};
        lli red = 0;
        for(int i=n-1;i>=0;i--)
        {
            for(int i=0;i<x.size();i++)
                cout<<(*x.find_by_order(i))<<" ";
                cout<<"\n";
            b[i] = (x.order_of_key(a[i]));
            x.insert(a[i]);
        }

        array_printer(b,n);

        lli ina=0;
        lli mx=-inf;
        for(int i=0;i<n;i++)
        {
            ina += b[i];
            mx = max(mx,b[i]);
        }
        cout<<(ina - mx)<<"\n";
        t--;
    }
    return 0;
}
