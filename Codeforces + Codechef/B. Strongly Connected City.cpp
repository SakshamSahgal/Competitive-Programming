#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool marked[401] = {0};

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

void matrix_printer(int r,int c,char *x)
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

map<int,vector<int>> g;
int cnt=0;

void Display()
{
    for(auto i: g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
}

void Reset_marked()
{
    for(int i=0; i<401; i++)
        marked[i] = 0;
}

void DFS(int v)
{
    if(marked[v] == 0)
    {
        cnt++;
        //cout<<v<<" ";
        marked[v] = 1;
    }

    for(int i=0; i < g[v].size(); i++)
    {
        if(marked[ g[v][i] ] == 0)
            DFS(g[v][i]);
    }
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n,m;
    cin>>n>>m;
    char nodesr[n][m];
    char nodesc[n][m];
    int  nodes[n][m];
    string r,c;
    cin>>r>>c;
    int counter=1;
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
        {
            nodesr[i][j] = r[i];
            nodes[i][j] = counter;
            counter++;
        }


    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            nodesc[j][i] = c[i];

    //matrix_printer(n,m,(char*) nodesr);
    //matrix_printer(n,m,(char*) nodesc);
    //matrix_printer(n,m,(int*) nodes);


    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if( nodesr[i][j] == '>' && ( j+1 < m) )
                g[nodes[i][j]].push_back(nodes[i][j+1]);

            if( nodesr[i][j] == '<' && ( j-1 >= 0) )
                g[nodes[i][j]].push_back(nodes[i][j-1]);

            if( nodesc[i][j] == '^' && (  i-1 >= 0) )
                g[nodes[i][j]].push_back(nodes[i-1][j]);

            if( nodesc[i][j] == 'v' && (  i+1 < n) )
                g[nodes[i][j]].push_back(nodes[i+1][j]);
        }
    }

    //Display();
    //DFS(1);

    for(int i=1; i<=(n*m); i++)
    {
        //cout<<"\n";
        DFS(i);
        //cout<<"\n";
        //cout<<"Count = "<<cnt<<"\n";
        if(cnt < (n*m) )
        {
            cout<<"NO\n";
            return 0;
        }
        else
        {
            cnt=0;
            Reset_marked();
        }

    }

    cout<<"YES\n";
    return 0;
}


