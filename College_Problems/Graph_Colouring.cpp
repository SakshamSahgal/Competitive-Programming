#include<iostream>
using namespace std;

bool adj_mat[100][100];

int color[1000];

bool is_possible(int v,int c,int n)
{
    for(int i=0; i<n; i++)
    {
        if(adj_mat[v][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

void print_adj(int n)
{
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
            cout<<adj_mat[i][j]<<" ";
        cout<<"\n";
    }
}

int mini = 1e5;

int calc(int v,int n,int mini_used)
{
    if(v == n)
    {
        cout<<"colors used = "<<mini_used<<"\n";
        cout<<"\n-----------------------\n";
        for(int i=0; i<n; i++)
            cout<<color[i]<<" ";
        cout<<"\n-----------------------\n";
        print_adj(n);
        mini = min(mini_used,mini);
    }

    for(int i=1; i<=n; i++)
    {
        if(is_possible(v,i,n))
        {
            cout<<"using color "<<i<<" with "<<v<<"\n";
            color[v] = i;
            mini_used = max(mini_used,i);
            calc(v+1,n,mini_used);
            color[v] = 0;
        }
    }

}



int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0; i<m; i++)
    {
        int a,b;
        cin>>a>>b;
        adj_mat[a][b] = 1;
        adj_mat[b][a] = 1;
    }

    calc(0,n,1);
    cout<<mini<<"\n";
    return 0;
}
