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
using namespace std;

is_good(lli n)
{
    vector<lli> x;
    while( n != 0)
    {
        x.insert(x.begin(),(n%3));
        n /= 3;
    }

    for(auto i:x)
    {
        if(!(i == 1 || i == 0))
            return 0;
    }
    return 1;
}

int main()
{
    //GO_FAST
    vector<lli> x;

    for(int i=1; i<=100000; i++)
        if(is_good(i))
            x.push_back(i);

   // for(auto i:x)
   //     cout<<i<<" ";
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        auto ptr = lower_bound(x.begin(),x.end(),n);
        cout<<(*ptr)<<"\n";
        t--;
    }
    return 0;
}
