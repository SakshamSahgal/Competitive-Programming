#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
map<int,vector<int>> graph;
map<int,int> c;
void display()
{
    for(auto i:graph)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }

}


void counter()
{
    for(auto i:graph)
    {
        for(auto j:i.second)
            c[j]++;
    }
}


void Map_printer(map<int,int> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

bool marked[150001];
map<int,int> sub_graph_size;
int k=0;

void DFS(int v)
{
    //cout<<v<<" ";
    k++;
    marked[v]=1;
    for(int i=0; i<graph[v].size(); i++)
    {
        if(marked[graph[v][i]] == 0)
            DFS(graph[v][i]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    for(int i=0; i<m; i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    display();
    counter();
    Map_printer(c);


    for(auto i:graph)
    {
        if(marked[i.first] == 0)
        {
            k=0;
            DFS(i.first);
            sub_graph_size[i.first] = k;
            cout<<"sub graph size of "<<i.first<<" = "<<sub_graph_size[i.first]<<"\n";

            for(auto j:i.second)
            {
                if( i.second.size() != ( sub_graph_size[i.first] - 1 ) || graph[j].size() !=  ( sub_graph_size[i.first] - 1 ) || c[i.first] != c[j])
                {
                    cout<<"NO\n";
                    goto b;
                }

            }
        }


    }

    cout<<"YES\n";

b:
    return 0;
}


