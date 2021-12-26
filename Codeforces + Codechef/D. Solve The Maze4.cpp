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



struct node
{
    char state = '.';
    bool visited = 0;
};

bool valid(int r,int c,int n,int m)
{
    return (r>=0 && r<n && c>=0 && c<m);
}

int dir[4][2] = { {1,0}, {0,1}, {-1,0}, {0,-1} };



int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n,m;
        cin>>n>>m;
        node grid[n][m];
        set<pair<int,int>> gb;
        set<pair<int,int>> bb;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>grid[i][j].state;
                if(grid[i][j].state == 'G')
                    gb.insert({i,j});
                if(grid[i][j].state == 'B')
                    bb.insert({i,j});
            }
        }

        if(gb.size() == 0) //only bad boys
            cout<<"YES\n";
        else
        {
            for(auto i:bb)
            {
                for(int k=0; k<4; k++)
                {
                    int r = i.first + dir[k][0]; //neighbour row
                    int c = i.second + dir[k][1]; //neighbour col
                    if( valid(r,c,n,m) == 1 )
                    {
                        if(grid[r][c].state == 'G')
                        {
                            cout<<"NO\n";
                            goto l;
                        }
                        else if(grid[r][c].state == '.')
                            grid[r][c].state = '#';
                    }
                }
            }

            /*
            for(int i=0; i<n; i++)
            {
                for(int j=0; j<m; j++)
                    cout<<grid[i][j].state<<" ";
                cout<<"\n";
            } */

            if(grid[n-1][m-1].state == '.')
            {
                {
                    //BFS
                    queue<pair<int,int>> s;

                    s.push({n-1,m-1});
                    grid[n-1][m-1].visited = 1;

                    while( !s.empty() )
                    {
                        pair<int,int> p = s.front();
                        s.pop();
                        //cout<<p.first<<" "<<p.second<<"\n";

                        for( int k=0; k<4; k++ )
                        {
                            int r = p.first + dir[k][0]; //neighbouring node row
                            int c = p.second + dir[k][1]; //neighbouring node col
                            if( valid(r,c,n,m) && grid[r][c].visited == 0 && grid[r][c].state != '#') //valid unvisited and not wall neighbours
                            {
                                grid[r][c].visited = 1;
                                s.push({r,c});
                            }
                        }
                    }
                }

                /*
                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                        cout<<grid[i][j].visited<<" ";
                    cout<<"\n";
                } */

                //see_visited(n,m);

                for(int i=0; i<n; i++)
                {
                    for(int j=0; j<m; j++)
                    {
                        if(grid[i][j].state == 'G' && grid[i][j].visited == 0 || grid[i][j].state == 'B' && grid[i][j].visited == 1)
                        {
                            cout<<"NO\n";
                            goto l;
                        }
                    }

                }
                cout<<"YES\n";
            }
            else
                cout<<"NO\n";



        }
l:
        t--;
    }
    return 0;
}
