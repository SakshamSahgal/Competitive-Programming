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
map<int,vector<int>> g;
bool marked[25000] = {0};
int c=0;
vector<int> vis;
void display()
{
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }

}

void DFS(int v)
{
    c++;
    //cout<<v<<" ";
    vis.push_back(v);
    marked[v] = 1;
    for(int i=0; i<g[v].size(); i++)
    {
        if(marked[ g[v][i] ] == 0)
            DFS(g[v][i]);
    }
}

void Reset_Visited()
{
    for(int i=0; i<25000; i++)
        marked[i] = 0;
}

void vector_printer( vector<int> v)
{
    //cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    //cout<<"\n------------------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;

        for(int i=1; i<=(n-1); i++)
            g[i].push_back(i+1);



        for(int i=1; i<=n; i++)
        {
            int x;
            cin>>x;

            if(x == 0)
                g[i].push_back(n+1);
            else
                g[n+1].push_back(i);
        }


        display();
        //for(auto i = g.begin(); i!=g.end(); i++)
           // sort(i->second.begin(),i->second.end());

        for(int i=1; i<=(n+1); i++)
        {
            //cout<<"\n";
            DFS(i);
            //cout<<"\n";
            if(c == n+1)
            {
                vector_printer(vis);
                cout<<"\n";
                goto l;
            }
            else
            {
                c=0;
                vis.clear();
                Reset_Visited();
            }
        }
        cout<<"-1\n";
l:

        c=0;
        vis.clear();
        g.clear();
        Reset_Visited();
        t--;
    }
    return 0;
}


