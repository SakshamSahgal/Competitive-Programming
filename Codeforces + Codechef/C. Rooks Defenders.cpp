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

    lli n,q;
    cin>>n>>q;
    ordered_set r;
    ordered_set c;
    map<lli,lli> rr;
    map<lli,lli> cc;
    while(q--)
    {
        lli t;
        cin>>t;
        if(t == 1)
        {
            lli x,y;
            cin>>x>>y;
            r.insert(x);
            c.insert(y);
            rr[x]++;
            cc[y]++;
        }
        else if(t == 2)
        {
            lli x,y;
            cin>>x>>y;
            rr[x]--;
            cc[y]--;
            if(rr[x] == 0)
                r.erase(r.find(x));
            if(cc[y] == 0)
                c.erase(c.find(y));
        }
        else
        {
            lli x1,y1,x2,y2;
            cin>>x1>>y1>>x2>>y2;
            lli l = (r.order_of_key(x1));
            lli h = (r.order_of_key(x2+1));

            lli l2 = (c.order_of_key(y1));
            lli h2 = (c.order_of_key(y2+1));

            //cout<<l<<" "<<h<<" "<<l2<<" "<<h2<<"\n";

            if( ( rr[x1] > 0 && rr[x2] > 0 && h-l-1 == x2-x1 ) || ( cc[y1] > 0  && cc[y2] > 0 && h2 - l2 - 1 == y2 - y1 ) )
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }

    return 0;
}
