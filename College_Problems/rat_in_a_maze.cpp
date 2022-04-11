#include<iostream>
using namespace std;

bool mat[100][100];
bool vis[100][100];

bool poss(int i,int j,int n,int m)
{
    if(i >= n || j >= m || mat[i][j] == 0)
        return 0;
    else
        return 1;
}

bool solve(int i,int j,int n,int m)
{
    //cout<<"{ "<<i<<" , "<<j<<" }\n";
    vis[i][j] = 1;
    if(i == n-1 && j == m-1)
        return 1;

    if(poss(i,j+1,n,m) && solve(i,j+1,n,m))
        return 1;
    if(poss(i+1,j,n,m) && solve(i+1,j,n,m))
        return 1;
    else
    {
        mat[i][j] = 0;
        vis[i][j] = 0;
        return 0;
    }
}

void trace_path(int n,int m)
{
    int i=0;
    int j=0;

    while(!(i == n-1 && j == m-1))
    {
        if(vis[i][j+1] == 1)
            cout<<i<<" , "<<(j++)<<"\n";
        else
            cout<<(i++)<<" , "<<j<<"\n";
    }
    cout<<n-1<<" , "<<m-1<<"\n";
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>mat[i][j];


    if(solve(0,0,n,m))
    {
        cout<<"solved\n";
//        for(int i=0;i<n;i++)
//        {
//            for(int j=0;j<m;j++)
//                cout<<vis[i][j];
//            cout<<"\n";
//        }
        trace_path(n,m);
    }

    else
        cout<<"not poss\n";


    return 0;
}
