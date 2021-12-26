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
map<int,vector<int>> g;
bool vis[100001] = {0};
bool c[100001] = {0};
int ans=0;
void DFS(int v,bool pass,int counter,int m)
{

    if(vis[v] == 0)
        vis[v] = 1;


    if(c[v] == 1)
        counter++;
    else
        counter = 0;

    if(counter > m)
        pass = 0;

    //cout<<v<<" counter = "<<counter<<" pass = "<<pass<<"\n";

    bool leaf = 1;
    for(auto i:g[v])
    {
        if(vis[i] == 0)
        {
            leaf = 0;
            DFS(i,pass,counter,m);
        }
    }

    if(leaf == 1)
    {
        //cout<<"Leaf\n";
        if(pass == 1)
            ans++;
    }

}

int main()
{
    //GO_FAST
    int n,m;
    cin>>n>>m;
    for(int i=1; i<=n; i++)
        cin>>c[i];
    for(int i=1; i<=(n-1); i++)
    {
        int a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    DFS(1,1,0,m);
    cout<<ans<<"\n";
    return 0;
}
