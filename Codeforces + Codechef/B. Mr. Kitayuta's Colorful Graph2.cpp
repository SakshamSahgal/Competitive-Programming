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

map<int,vector<pair<int,int>>> graph;
set<int> distinct_colors;
bool visited[101] = {0};
bool this_color_found=0;

void DFS(int st,int ed,int col)
{
    //cout<<st<<" ";
    int v = st;
    visited[v] = 1;

    if(st == ed)
    {
        this_color_found = 1;
        return;
    }

    if(this_color_found == 1)
        return;
    else
    {
        for(int i=0; i<graph[v].size(); i++)
        {
            if(visited[ graph[v][i].first  ] == 0 && graph[v][i].second == col)
                DFS(graph[v][i].first,ed,col);
        }
    }

}

void display()
{
    for(auto i:graph)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
        {
            cout<<"("<<j.first<<" "<<j.second<<") ";
        }
        cout<<"\n";
    }
}

void reset_visited()
{
    for(int i=0; i<101; i++)
        visited[i]=0;
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
        int a,b,c;
        cin>>a>>b>>c;
        graph[a].push_back({b,c});
        graph[b].push_back({a,c});
    }


    for(auto i:graph)
        sort(i.second.begin(),i.second.end());
    //display();
    int q;
    cin>>q;
    for(int i=0; i<q; i++)
    {
        int a,b,ct=0;
        cin>>a>>b;

        for(int j=1; j<=m; j++)
        {
            this_color_found=0;
            //cout<<"\ntrying color "<<j<<"\n";
            DFS(a,b,j);
            if(this_color_found == 1)
                ct++;
            reset_visited();
        }

        cout<<ct<<"\n";
    }

    return 0;
}


