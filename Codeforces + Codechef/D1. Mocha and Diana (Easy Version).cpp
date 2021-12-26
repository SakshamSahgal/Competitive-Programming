#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
using namespace std;
map<int,vector<int>> g1;
map<int,vector<int>> g2;

lli p1[1001];
lli p2[1001];

int get_Parent(int x,int graph_no) //gets you absolute parent
{
    if(graph_no == 1)
    {
        if(p1[x] < 0) //-ve means absolute parent
            return x;
        else
            return (get_Parent(p1[x],1));
    }
    else
    {
        if(p2[x] < 0) //-ve means absolute parent
            return x;
        else
            return (get_Parent(p2[x],2));
    }
}


bool cycle_Detected(int a,int b,int graph_no)
{
    if(get_Parent(a,graph_no) == get_Parent(b,graph_no))
        return 1;
    else
        return 0;
}


void union_set(int a,int b,int graph_no)
{
    if(graph_no == 1)
    {
        int pa = get_Parent(a,1);
        int pb = get_Parent(b,1);
        //cout<<"abs parent of "<<a<<" is "<<pa<<" set size = "<<abs(p1[pa])<<"\n";
        //cout<<"abs parent of "<<b<<" is "<<pb<<" set size = "<<abs(p1[pb])<<"\n";
        if(pa != pb)
        {
            if(abs(p1[pa]) >= abs(p1[pb])) //if set a is bigger
            {
                //adding set b to set a
                p1[pa] += p1[pb];
                p1[pb] = pa;
                //cout<<"adding set "<<b<<" to set "<<a<<" , now set size = "<<abs(p1[pa])<<" with parent "<<pa<<"\n";
            }
            else
            {
                //adding set a to set b
                p1[pb] += p1[pa];
                p1[pa] = pb;
                //cout<<"adding set "<<a<<" to set "<<b<<" , now set size = "<<abs(p1[pb])<<" with parent "<<pb<<"\n";
            }
        }
    }
    else
    {
        int pa = get_Parent(a,2);
        int pb = get_Parent(b,2);
        //cout<<"abs parent of "<<a<<" is "<<pa<<" set size = "<<abs(p2[pa])<<"\n";
        //cout<<"abs parent of "<<b<<" is "<<pb<<" set size = "<<abs(p2[pb])<<"\n";
        if(pa != pb)
        {
            if(abs(p2[pa]) >= abs(p2[pb])) //if set a is bigger
            {
                //adding set b to set a
                p2[pa] += p2[pb];
                p2[pb] = pa;
                //cout<<"adding set "<<b<<" to set "<<a<<" , now set size = "<<abs(p2[pa])<<" with parent "<<pa<<"\n";
            }
            else
            {
                //adding set a to set b
                p2[pb] += p2[pa];
                p2[pa] = pb;
                //cout<<"adding set "<<a<<" to set "<<b<<" , now set size = "<<abs(p2[pb])<<" with parent "<<pb<<"\n";
            }
        }
    }
}

bool edge_exist(int u,int v,int graph_no)
{
    if(graph_no == 1)
    {
        auto map_itr = g1.find(u);
        if(map_itr != g1.end())
        {
            auto vec_itr = find(g1[u].begin(),g1[u].end(),v);
            if(vec_itr != g1[u].end())
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
    else
    {
        auto map_itr = g2.find(u);
        if(map_itr != g2.end())
        {
            auto vec_itr = find(g2[u].begin(),g2[u].end(),v);
            if(vec_itr != g2[u].end())
                return 1;
            else
                return 0;
        }
        else
            return 0;
    }
}

void Display(int graph_no)
{
    cout<<"\n----------------------\n";
    if(graph_no == 1)
    {
        for(auto i:g1)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
                cout<<j<<" ";
            cout<<"\n";
        }
    }
    else
    {
        for(auto i:g2)
        {
            cout<<i.first<<" -> ";
            for(auto j:i.second)
                cout<<j<<" ";
            cout<<"\n";
        }
    }
    cout<<"\n----------------------\n";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
memset(p1, -1, sizeof(p1));
memset(p2, -1, sizeof(p2));
    int n,m1,m2;
    cin>>n>>m1>>m2;

    for(int i=0; i<m1; i++)
    {
        int x,y;
        cin>>x>>y;
        g1[x].push_back(y);
        g1[y].push_back(x);
        union_set(x,y,1);
    }

    for(int i=0; i<m2; i++)
    {
        int x,y;
        cin>>x>>y;
        g2[x].push_back(y);
        g2[y].push_back(x);
        union_set(x,y,2);
    }

    //Display(1);
    //Display(2);

    vector<pair<int,int>> v;
    for(int i=1; i<=n; i++)
    {
        for(int j = i+1; j<=n; j++)
        {
            if( ( edge_exist(i,j,1) == 0 ) && ( edge_exist(i,j,2) == 0 ) && ( cycle_Detected(i,j,1) == 0 ) && ( cycle_Detected(i,j,2) == 0) )
            {
                v.push_back({i,j});
                g1[i].push_back(j);
                g1[j].push_back(i);
                union_set(i,j,1);

                g2[i].push_back(j);
                g2[j].push_back(i);
                union_set(i,j,2);
            }
        }
    }

    cout<<v.size()<<"\n";

    for(auto i:v)
        cout<<i.first<<" "<<i.second<<"\n";

    return 0;
}


