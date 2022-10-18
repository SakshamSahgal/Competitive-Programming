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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}

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
        vector<pair<lli,lli>> v;
        lli x;
        map<lli,lli> f;
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            if(i > x)
            v.push_back({i,x});
        }
        //pair_printer(v);
        vector<lli> ans(v.size());
        ordered_multiset xx;
        lli s=0;
        for(int i=v.size()-1;i>=0;i--)
        {
            lli z = (xx.size()) - (xx.order_of_key(v[i].first)) - f[v[i].first];
            ans[i] = z;
            xx.insert(v[i].second);
            f[v[i].second]++;
        }
        //vector_printer(ans);
        for(auto i:ans)
            s += i;
        cout<<s<<"\n";
        t--;
    }
    return 0;
}
