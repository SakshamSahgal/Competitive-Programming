#include<iostream>
using namespace std;


void 2d_array_printer()
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cout<<vis[i][j];
        cout<<"\n";
    }

}

int main()
{
    int n,m;
    cin>>n>>m;

    int **vis;
    vis = new int *[n];

    for(int i=0;i<n;i++)
        vis[i] = new int[m];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
            cin>>vis[i][j];
    }

    2d_array_printer(n,m,vis);

    return 0;
}

