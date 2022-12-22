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
    //GO_FAST
    ordered_set x;
    x.insert(5);
    x.insert(4);
    x.insert(3);
    x.insert(1);
    x.insert(3);
    x.erase(x.find(1));
    for(int i=0;i<x.size();i++)
        cout<<(*x.find_by_order(i))<<" "; //you can access the ith index of an ordered-set in log(n) by using x.find_by_order(i);

    cout<<"\n no of elements smaller than 5 = "<<(x.order_of_key(5))<<"\n"; //no of elements smaller that 5 in log(n)

    ordered_multiset xx;
    xx.insert(2);
    xx.insert(2);
    xx.insert(2);
    xx.insert(1);
    xx.insert(1);
    xx.insert(1);
    xx.insert(3);
    xx.insert(3);
    xx.insert(3);


    for(int i=0;i<xx.size();i++)
        cout<<(*xx.find_by_order(i))<<" ";

    cout<<"\n no of elements smaller than 2 = "<<(xx.order_of_key(2))<<"\n"; //no of elements smaller that 2 in log(n)

    return 0;
}

