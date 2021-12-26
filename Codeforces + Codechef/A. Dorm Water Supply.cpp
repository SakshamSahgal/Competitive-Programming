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

struct pipe
{
    lli to;
    lli dia;
    bool inc=0;
};

struct aans
{
int from;
int to;
int d;
};
vector<aans> ans;

bool marked[100000] = {0};
map<lli,vector<pipe>> g;
lli mini = INT_MAX;
lli st;
void Display()
{
    cout<<"\n----------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<" ("<<j.to<<" "<<j.dia<<" "<<j.inc<<") ";
        cout<<"\n";
    }
    cout<<"\n----------------------\n";
}


void DFS(int v)
{
    //cout<<v<<"\n";
    if(marked[v] == 0)
        marked[v] = 1;
    bool dead_end=1;
    for(auto i:g[v])
    {
        if(i.inc == 0 && marked[i.to] ==  0)
        {
            if( i.dia < mini )
                mini = i.dia;
            dead_end = 0;
            DFS(i.to);
        }
    }

    if(dead_end == 1)
    {
       // cout<<st<<" "<<v<<" "<<mini<<"\n";
        ans.push_back({st,v,mini});
    }

}

int main()
{

    GO_FAST
    int n,p;
    cin>>n>>p;
    for(int i=0; i<p; i++)
    {
        int a,b,d;
        cin>>a>>b>>d;
        g[a].push_back({b,d,0});
        g[b].push_back({a,d,1});
    }
   // Display();

    for(auto i:g)
    {
       // cout<<"at = "<<i.first<<" ";
        if(i.second.size() == 1)
        {
            if(i.second[0].inc == 0)
            {
               st = i.first;
                mini = INT_MAX;
                DFS(i.first);
            }
        }
    }

    cout<<ans.size()<<"\n";

    for(auto i:ans)
    cout<<i.from<<" "<<i.to<<" "<<i.d<<"\n";

    return 0;
}
