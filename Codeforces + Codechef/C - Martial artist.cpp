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

map<lli,vector<lli>> g;

void Display()
{
    cout<<"\n----------------------\n";

    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n----------------------\n";
}

bool vis[200001] = {0};
lli ans = 0;
lli t[200001];
void DFS(lli v)
{
    //cout<<v<<"\n";
    ans += t[v];
    vis[v] = 1;
    for(auto i:g[v])
    {
        if(vis[i] == 0)
            DFS(i);
    }
}

int main()
{
    GO_FAST

    lli n;
    cin>>n;

    for(int i=1; i<=n; i++)
    {
        cin>>t[i];
        lli k;
        cin>>k;
        lli a[k];
        for(int j=0; j<k; j++)
        {
            cin>>a[j];
            g[i].push_back(a[j]);
        }
    }

    for(auto i = g.begin(); i!= g.end(); i++)
        sort(i->second.begin(),i->second.end());


    //Display();
    DFS(n);
    cout<<ans<<"\n";
    return 0;
}
