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

//-----------------------------------------------------PBDS Library Imports--------------------------------------------------------

#include <ext/pb_ds/assoc_container.hpp> // Common file
#include <ext/pb_ds/tree_policy.hpp> // Including
using namespace __gnu_pbds;
typedef tree<lli,null_type,less<lli>,rb_tree_tag,tree_order_statistics_node_update> ordered_set;
typedef tree<pll,null_type,less<pll>,rb_tree_tag,tree_order_statistics_node_update> ordered_multiset;
//accending order -> less<int>
//decending order -> greater<int>
//if you want character ordered set/multiset change the int to char

//---------------------------------------------------------------------------------------------------------------------------------

void PBDS_Ordered_Multiset_printer(ordered_multiset &x)
{
    line_printer(20);
    for(int i=0; i<x.size(); i++)
        cout<<(*x.find_by_order(i)).first<<" ";
    line_printer(20);
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    line_printer(30);
    cout<<"Ordered Set - \n";

    ordered_set x;
    x.insert(1);
    x.insert(10);
    x.insert(2);
    x.insert(7);
    x.insert(2);
    x.insert(6);
    //Ordered set only contains unique values
    for(auto i:x)
        cout<<i<<" ";

    cout<<"\n";
    //Accessing by index
    for(int i=0; i<x.size(); i++)
        cout<<(*x.find_by_order(i))<<" ";

    cout<<"\n";
    //No of elements strictly smaller than 6
    cout<<"No of elements strictly smaller than 6 = "<<x.order_of_key(6)<<"\n";
    cout<<"No of elements strictly smaller than 7 = "<<x.order_of_key(7)<<"\n";
    cout<<"No of elements strictly smaller than 1 = "<<x.order_of_key(1)<<"\n";

    //Lower Bound of 6
    cout<<"Lower bound of 6 (first element >= 6) = "<<(*x.lower_bound(6))<<"\n";
    //Upper Bound of 6
    cout<<"Upper bound of 6 (first element > 6) = "<<(*x.upper_bound(6))<<"\n";

    cout<<"Deleting 10 \n";
    x.erase(10);
    x.erase(11); //if not present then nothing will happen (no error)
    for(auto i:x)
        cout<<i<<" ";

    line_printer(30);

    line_printer(30);

    cout<<"Ordered Multiset - \n";

    lli dc=0; //difference counter (just use a difference counter to make same elements different)
    ordered_multiset xx;

    xx.insert({1,dc++});
    xx.insert({10,dc++});
    xx.insert({2,dc++});
    xx.insert({7,dc++});
    xx.insert({2,dc++});
    xx.insert({6,dc++});
    xx.insert({6,dc++});
    //Ordered Multiset set
    for(auto i:xx)
        cout<<i.first<<" ";

    cout<<"\n";
    //Accessing by index
    for(int i=0; i<xx.size(); i++)
        cout<<(*xx.find_by_order(i)).first<<" ";

    cout<<"\n";
    //No of elements strictly smaller than 6
    cout<<"No of elements strictly smaller than 6 = "<<xx.order_of_key({6,0})<<"\n";
    cout<<"No of elements strictly smaller than 7 = "<<xx.order_of_key({7,0})<<"\n";
    cout<<"No of elements strictly smaller than 1 = "<<xx.order_of_key({1,0})<<"\n";

    //Lower Bound of 6
    cout<<"Lower bound of 6 (first element >= 6) = "<<(*xx.lower_bound({6,0})).first<<"\n";
    cout<<"Lower bound of 20 (first element >= 20) = "<<((xx.lower_bound({20,0})) == xx.end())<<"\n";
    //Upper Bound of 6
    cout<<"Upper bound of 6 (first element > 6) = "<<(*xx.upper_bound({6,inf})).first<<"\n";

    cout<<"Deleting 6 \n";
    xx.erase((*xx.lower_bound({6,0}))); //erasing only one instance of 6
    xx.erase((*xx.lower_bound({11,0}))); //if pair is not present then no problem
    for(auto i:xx)
        cout<<i.first<<" ";

    cout<<"smallest no = "<<(*xx.lower_bound({-inf,-inf})).first<<"\n";


    line_printer(30);

    return 0;
}

