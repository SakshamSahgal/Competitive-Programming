#include<iostream>
using namespace std;

bool mat[100][100];
bool vis[100][100];




int main()
{
    int n,m;
    cin>>n>>m;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];

    return 0;
}
