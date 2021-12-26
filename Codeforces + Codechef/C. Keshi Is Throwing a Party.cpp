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


void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        map<lli,lli> m;
        map<lli,lli> m2;
        lli d[n+1];
        d[0] = INT_MAX;
        for(lli i=1; i<=n; i++)
        {
            d[i] = INT_MAX;
            lli a,b;
            cin>>a>>b;
            lli up = min(i + a,n);
            lli down = max((lli)1,i-b);
            m[down]++;
            m[up+1]--;
        }

        lli sum=0;

        for(auto i:m)
        {
            sum += i.second;
            m2[i.first] = sum;
        }

        Map_printer(m2);

        map<lli,lli> freq;

        for(auto i:m2)
        {
            if(i.first <= n)
                    d[i.first] = i.second;
        }

        lli last = 0;

        for(int i=1;i<=n;i++)
        {
            if(d[i] != INT_MAX)
            {

            }
        }

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
