#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>


#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

typedef tree<int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> indexed_set;

int main()
{
    //GO_FAST
    indexed_set s;
    lli n,k;
    cin>>n>>k;
    k--;
    vector<lli> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    for(lli i=0; i<k; i++)
        s.insert(v[i]);

    lli temp = 0;
    for(int i=k; i<n; i++)
    {
        s.insert(v[i]);
        auto x = s.find_by_order(s.size() - k - 1);
        cout<<*x<<"\n";
    }
    return 0;
}
