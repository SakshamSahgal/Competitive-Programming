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
map<int,vector<pair<int,int>>> g;
bool visited[101] = {0};
lli maxx = INT_MIN;
void DFS(int v,lli sum)
{
    maxx = max(sum,maxx);
    //cout<<v<<" "<<"stn = "<<sum<<"\n";
    if(visited[v] != 1)
        visited[v] = 1;
    for(auto i:g[v])
    {
        if(visited[i.first] == 0)
        {
            DFS(i.first,sum+i.second);
        }
    }
}

int main()
{
    GO_FAST
    int n;
    cin>>n;

    for(int i=0; i<n-1; i++)
    {
        int u,v,c;
        cin>>u>>v>>c;
        g[u].push_back({v,c});
        g[v].push_back({u,c});
    }

    DFS(0,0);
    cout<<maxx<<"\n";
    return 0;
}
