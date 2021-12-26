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
bool visited[101]= {0};
map<int,vector<pair<int,int>>> gph;
lli journey=0;
void DFS(int v)
{
    //cout<<v<<" ";
    visited[v] = 1;
    bool ending=1;
    for(int i=0; i<gph[v].size(); i++)
    {
        if(visited[gph[v][i].first]  == 0)
        {
            ending = 0;
            journey += gph[v][i].second;
            DFS(gph[v][i].first);
        }
    }

    if(ending == 1)
        journey += gph[v][0].second;
}

void sort_graph()
{
    for(auto i=gph.begin();i!=gph.end();i++)
        sort(i->second.begin(),i->second.end());
}

display()
{
    for(auto i:gph)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<" ("<<j.first<<" "<<j.second<<") ";

        cout<<"\n";
    }
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int n;
    cin>>n;
    lli tot_wt=0;
    for(int i=0; i<n; i++)
    {
        int a,b,w;
        cin>>a>>b>>w;
        tot_wt+=w;
        gph[a].push_back({b,0});
        gph[b].push_back({a,w});
    }

    sort_graph();
    //display();
    DFS(1);
    //cout<<"journey = "<<journey<<"\n";
    cout<<min(tot_wt-journey,journey);


    return 0;
}

