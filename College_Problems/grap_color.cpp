#include<iostream>
using namespace std;

int adj[100][100];
int color[100];

int mini = 1e5;


bool is_pos(int v,int c,int n)
{
    for(int i=0;i<n;i++)
    {
        if(adj[v][i] == 1 && color[i] == c)
            return 0;
    }
    return 1;
}

int count_dist(int n)
{
    int c=0;
   for(int i=1;i<=n;i++)
   {
       if(color[i] != 0)
            c++;
   }
   return c;
}


void calc(int v,int n)
{
    //cout<<"v = "<<v<<"\n";
    if(v == n)
    {
        //cout<<"done\n";
        //cout<<"dist colors used = "<<count_dist(n)<<"\n";
        mini = min(mini,count_dist(n));
        return;
    }

    for(int i=1;i<=n;i++)
    {
        if(is_pos(v,i,n) == 1)
        {
            //cout<<" using color "<<i<<" for vertex "<<v<<"\n";
            color[v] = i;
            calc(v+1,n);
            color[v]= 0;
        }
    }
}

int main()
{
    int n,m;
    cin>>n>>m;

    for(int i=0;i<m;i++)
    {
        int a,b;
        cin>>a>>b;
        adj[a][b] = 1;
        adj[b][a] = 1;
    }
    calc(0,n);
    cout<<"mini = "<<mini<<"\n";
    return 0;
}
