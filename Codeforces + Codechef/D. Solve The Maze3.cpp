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
char grid_state[50][50];
int grid_ID[50][50];
int dir[4][2] = { {0,1}, {1,0}, {-1,0}, {0,-1} };

bool valid(int r,int c,int n,int m)
{
    return (r>=0 && r<n && c >=0 && c<m);
}

int distance = 0;

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
    memset(marked,0,sizeof(marked));
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



bool Knit_Graph(int n,int m)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(grid_state[i][j] != '#')
            {
                for(int k=0; k<4; k++)
                {
                    int r = i + dir[k][0];
                    int c = j + dir[k][1];
                    if( valid(r,c,n,m) && grid_state[r][c] != '#' )
                    {
                        g[grid_ID[i][j]].push_back(grid_ID[r][c]);
                        if(grid_state[i][j] == 'B' && grid_state[r][c] == 'G' || grid_state[i][j] == 'G' && grid_state[r][c] == 'B')
                            return 0;
                    }
                }
            }
        }
    }
    return 1;
}
void matrix_printer(int r,int c,int *x)
{
    cout<<"\n";
    for(int i=0; i<r; i++)
    {
        for(int j=0; j<c; j++)
            cout<<*((x+i*c)+j)<<" ";
        cout<<"\n";
    }
    cout<<"\n";
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        g.clear();
        int n,m;
        cin>>n>>m;
        int id=1;
        map<pair<int,int>,int> gb;
        map<pair<int,int>,int> bb;
        int dist[n][m];
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                dist[i][j] = -1;
                cin>>grid_state[i][j];
                grid_ID[i][j] = id;

                if(grid_state[i][j] == 'G')
                    gb[{i,j}] = grid_ID[i][j];
                else if(grid_state[i][j] == 'B')
                    bb[{i,j}] = grid_ID[i][j];
                id++;
            }
        }

        if(gb.size() == 0) //only bad boys
            cout<<"YES\n";
        else if(bb.size() == 0) //only good boys
        {
            g.clear();
            bool h = Knit_Graph(n,m);
            Display();

            BFS((n*m),n,m);


            for(auto i:gb)
            {
                Reset();
                int r = i.first.first;
                int c = i.first.second;
                if(BFS(grid_ID[r][c],n,m) == 0)
                {
                    cout<<"NO\n";
                    goto l;
                }
            }
            cout<<"YES\n";
        }
        else
        {
            for(auto i:bb)
            {
                int r = i.first.first;
                int c = i.first.second;
                for(int k=0; k<4; k++)
                {
                    int r1 = r + dir[k][0];
                    int c1 = c + dir[k][1];
                    if(valid(r1,c1,n,m) && grid_state[r1][c1] == '.')
                        grid_state[r1][c1] = '#';
                }
            }

            if(Knit_Graph(n,m) == 0)
            {
                cout<<"NO\n";
                goto l;
            }
            else
            {
                //Display();
                for(auto i:gb)
                {
                    Reset();
                    int r = i.first.first;
                    int c = i.first.second;
                    if(BFS(grid_ID[r][c],n,m) == 0)
                    {
                        cout<<"NO\n";
                        goto l;
                    }
                }
                cout<<"YES\n";
            }
        }
l:
        g.clear();
        t--;
    }
    return 0;
}

