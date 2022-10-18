#include <bits/stdc++.h>
using namespace std;


bool vis[1000][1000];

void DFS(int i,int j,int n,int m,vector<vector<int>> &islands)
{
    vis[i][j] = 1;
    if(i-1 >= 0 && vis[i-1][j] == 0 && islands[i-1][j] == 1)
        DFS(i-1,j,n,m,islands); //above
    if(j+1<m && vis[i][j+1] == 0 && islands[i][j+1] == 1)
        DFS(i,j+1,n,m,islands); //right
    if(i+1<n && vis[i+1][j] == 0 && islands[i+1][j] == 1)
        DFS(i+1,j,n,m,islands); //below
    if(j-1 >= 0 && vis[i][j-1] == 0 && islands[i][j-1] == 1)
        DFS(i,j-1,n,m,islands); //left
}


int main()
{
    // Write your code here

    int n,m;
    cin>>n>>m;
    std::vector<vector<int>> islands(n,vector<int>(m));
    int no_of_islands = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0;j<m; j++)
        {
            cin>>islands[i][j];
        }
    }

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(islands[i][j] == 1 && vis[i][j] == 0)
            {
                DFS(i,j,n,m,islands);
                no_of_islands++;
            }

        }
    }
    cout<<no_of_islands<<"\n";

    return 0;
}
