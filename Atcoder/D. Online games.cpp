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

int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    map<lli,lli> m;
    map<lli,lli> m2;
    map<lli,lli> c;
    for(int i=0,a,b; i<n; i++)
    {
        cin>>a>>b;
        m[a]++;
        m[a+b]--;
    }
    lli sum=0;

    for(auto i:m)
    {
        sum += i.second;
        m2[i.first] = sum;
    }

    for(auto i = m2.begin();i!= m2.end();i++)
    {
        if( i->first != m2.rbegin()->first)
        {
            auto j = i;
            j++;
            lli next = j->first;
            c[(i->second)] += (next - (i->first));
        }
        else
           c[i->second]++;
    }



    for(lli i=1; i<=n; i++)
        cout<<c[i]<<" ";


    return 0;
}
