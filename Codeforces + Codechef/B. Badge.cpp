#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

bool marked[1001] = {0};

map<int,vector<int>> g;

void DFS(int v)
{
    //cout<<v<<" ";
    marked[v]=1;
    bool found_a_way=0;
    for(auto i:g[v])
    {
        if(marked[i] == 0)
        {
            found_a_way = 1;
            DFS(i);
        }
    }


    if(found_a_way == 0)
        cout<<g[v][0]<<" ";

}


void reset_marked()
{
    for(int i=0;i<1001;i++)
        marked[i] = 0;
}

int main()
{
    //GO_FAST
    int n;
    cin>>n;
    int p[n+1];
    for(int i=1;i<=n;i++)
    {
        cin>>p[i];
        g[i].push_back(p[i]);
    }

    for(int i=1;i<=n;i++)
    {
        reset_marked();
        DFS(i);
    }
    return 0;
}

