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


int main()
{
    GO_FAST
    ordered_multiset xx;
    int t;
    cin>>t;
    while(t)
    {
        lli c;
        cin>>c;
        if(c == 1)
        {
            lli x;
            cin>>x;
            xx.insert(x);
        }
        else if(c == 2)
        {
            lli x,k;
            cin>>x>>k;
            lli ltoetx = (xx.order_of_key(x+1));
            lli index = ltoetx - k;
            if(index < 0)
                cout<<-1<<"\n";
            else
                cout<<(*xx.find_by_order(index))<<"\n";
        }
        else
        {
            lli x,k;
            cin>>x>>k;
            lli ltx = (xx.order_of_key(x));
            lli index = ltx + k - 1;
            if(index < xx.size())
                cout<<(*xx.find_by_order(index))<<"\n";
            else
                cout<<"-1\n";
        }
        t--;
    }
    return 0;
}

