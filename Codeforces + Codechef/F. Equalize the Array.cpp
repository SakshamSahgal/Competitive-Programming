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

lli calc(map<lli,lli> &ff,lli x)
{
    lli ans=0;
    for(auto i:ff)
    {
        if(i.first >= x)
            ans += (i.first - x)*i.second;
        else
            ans += i.second;
    }
    return ans;
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
        lli a[n];
        map<lli,lli> f;
        map<lli,lli> ff;

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }

        for(auto i:f)
            ff[i.second]++;

        lli ans=INT_MAX;
        for(auto i:ff)
        {
            ans = min(ans,calc(ff,i.first));
            cout<<i.first<<" "<<calc(ff,i.first)<<"\n";
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
