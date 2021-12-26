#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<queue>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
bool marked[100000] = {0};
map<int,vector<int>> g;

void BFS(int st)
{
    queue<int> q;
    q.push(st);
    marked[st] = 1;
    while(!q.empty())
    {
        int v = q.front();
        q.pop();

        cout<<v<<" ";

        for(auto i:g[v])
        {
            if(marked[i] == 0)
            {
                marked[i] = 1;
                q.push(i);
            }
        }
    }
}

void Add_Edge(int x,int y)
{
    g[x].push_back(y);
    g[y].push_back(x);
}

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

int main()
{
    Add_Edge(1,2);
    Add_Edge(1,3);
    Add_Edge(2,4);
    Add_Edge(2,5);
    Add_Edge(5,6);
    Add_Edge(3,7);
    Display();
    BFS(1);
    return 0;
}

