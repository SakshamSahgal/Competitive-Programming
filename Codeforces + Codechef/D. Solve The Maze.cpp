#include<iostream>
#include<cstring>
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
map<int,vector<int>> g;
bool marked[2501] = {0};
bool BFS(int st,int n,int m)
{
    queue<int> q;
    q.push(st);

    while(q.size() > 0)
    {
        int v = q.front();
        q.pop();
        if(marked[v] == 0)
        {
            //cout<<v<<" ";
            if(v == n*m)
                return 1;

            marked[v] = 1;
        }

        for(auto i:g[v])
        {
            if(marked[i] == 0)
                q.push(i);
        }
    }

    return 0;
}

void Reset()
{
    memset(marked,0,sizeof(a));
}

void delete_node(int x)
{
    auto map_itr = g.find(x);
    if(map_itr != g.end())
        g.erase(map_itr);
}

void delete_Edge(int x,int y)
{
    auto map_itr = g.find(x);
    if(map_itr != g.end())
    {
        auto vec_itr = find(g[x].begin(),g[x].end(),y);
        if(vec_itr != g[x].end())
            g[x].erase(vec_itr);
    }
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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n,m;
        cin>>n>>m;
        char grid_state[n][m];
        map<pair<int,int>,int> gb;
        map<pair<int,int>,int> bb;
        int grid_ID[n][m];
        int no=1;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>grid_state[i][j];
                grid_ID[i][j] = no;
                if(grid_state[i][j] == 'G')
                    gb[ {i,j}] = grid_ID[i][j];
                if(grid_state[i][j] == 'B')
                    bb[ {i,j}] = grid_ID[i][j];
                no++;
            }
        }

        if(gb.size() == 0) //only bad boys
            cout<<"YES\n";
        else if(bb.size() == 0) //only good boys
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(grid_state[i][j] != '#')
                    {
                        if(i-1 >= 0 && grid_state[i-1][j] != '#') // up
                            g[grid_ID[i][j]].push_back(grid_ID[i-1][j]);
                        if(i+1 < n && grid_state[i+1][j] != '#') //down
                            g[grid_ID[i][j]].push_back(grid_ID[i+1][j]);
                        if(j-1 >= 0 && grid_state[i][j-1] != '#') //left
                            g[grid_ID[i][j]].push_back(grid_ID[i][j-1]);
                        if(j+1 < m && grid_state[i][j+1] != '#') //right
                            g[grid_ID[i][j]].push_back(grid_ID[i][j+1]);
                    }
                }
            }

            //Display();


            for(auto i:gb)
            {
                Reset();
                int r = i.first.first;
                int c = i.first.second;
                if(BFS(i.second,n,m)  == 0)
                {
                    cout<<"NO\n";
                    goto k;
                }
            }
        }
        else
        {
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(grid_state[i][j] != '#')
                    {
                        if(i-1 >= 0 && grid_state[i-1][j] != '#') // up
                            g[grid_ID[i][j]].push_back(grid_ID[i-1][j]);
                        if(i+1 < n && grid_state[i+1][j] != '#') //down
                            g[grid_ID[i][j]].push_back(grid_ID[i+1][j]);
                        if(j-1 >= 0 && grid_state[i][j-1] != '#') //left
                            g[grid_ID[i][j]].push_back(grid_ID[i][j-1]);
                        if(j+1 < m && grid_state[i][j+1] != '#') //right
                            g[grid_ID[i][j]].push_back(grid_ID[i][j+1]);
                    }
                }
            }

            //Display();

            for(auto i:bb)
            {
                Reset();
                int r = i.first.first;
                int c = i.first.second;
                //cout<<"exploring bb ID = "<<i.second<<" r = "<<r<<" c = "<<c<<"\n";
                if(BFS(i.second,n,m) == 1)
                {
                    //cout<<"it can reach \n";
                    if(r-1 >=0 && grid_state[r-1][c] == '.' ) //up
                    {
                        grid_state[r-1][c] = '#';
                        delete_Edge(grid_ID[r][c],grid_ID[r-1][c]);
                        delete_Edge(grid_ID[r-1][c-1],grid_ID[r-1][c]);
                        delete_Edge(grid_ID[r-1][c+1],grid_ID[r-1][c]);
                        delete_Edge(grid_ID[r-2][c],grid_ID[r-1][c]);
                        delete_node(grid_ID[r-1][c]);
                    }
                    if(r+1 < n && grid_state[r+1][c] == '.') //down
                    {
                        grid_state[r+1][c] = '#';
                        delete_Edge(grid_ID[r][c],grid_ID[r+1][c]);
                        delete_Edge(grid_ID[r+1][c-1],grid_ID[r+1][c]);
                        delete_Edge(grid_ID[r+1][c+1],grid_ID[r+1][c]);
                        delete_Edge(grid_ID[r+2][c],grid_ID[r+1][c]);
                        delete_node(grid_ID[r-1][c]);
                    }
                    if(c-1 >=0 && grid_state[r][c-1] == '.') //left
                        grid_state[r][c-1] = '#';
                    if(c+1 < m && grid_state[r][c+1] == '.') //right
                        grid_state[r][c+1] = '#';
                }
            }

            g.clear();

            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                {
                    if(grid_state[i][j] != '#')
                    {
                        if(i-1 >= 0 && grid_state[i-1][j] != '#') // up
                            g[grid_ID[i][j]].push_back(grid_ID[i-1][j]);
                        if(i+1 < n && grid_state[i+1][j] != '#') //down
                            g[grid_ID[i][j]].push_back(grid_ID[i+1][j]);
                        if(j-1 >= 0 && grid_state[i][j-1] != '#') //left
                            g[grid_ID[i][j]].push_back(grid_ID[i][j-1]);
                        if(j+1 < m && grid_state[i][j+1] != '#') //right
                            g[grid_ID[i][j]].push_back(grid_ID[i][j+1]);
                    }
                }
            }

            //Display();

            for(auto i:bb)
            {
                Reset();
                int r = i.first.first;
                int c = i.first.second;
                //cout<<"exploring bb ID = "<<i.second<<" r = "<<r<<" c = "<<c<<"\n";
                if(BFS(i.second,n,m) == 1)
                {
                    cout<<"NO\n";
                    goto k;
                }
            }


            for(auto i:gb)
            {
                Reset();
                int r = i.first.first;
                int c = i.first.second;
                //cout<<"exploring GB ID = "<<i.second<<" r = "<<r<<" c = "<<c<<"\n";
                if( BFS(i.second,n,m) == 0 )
                {
                    cout<<"NO\n";
                    goto k;
                }
                Reset();
            }
            cout<<"YES\n";
        }
k:
        t--;
    }
    return 0;
}

