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

bool marked[100000];
map<int,vector<int>> gph;


void Eular_Tree_Tour(int v,int p)
{
    cout<<v<<" ";
    marked[v] = 1;
    for(int i=0; i<gph[v].size(); i++)
    {
        if(marked[gph[v][i]] == 0)
            Eular_Tree_Tour(gph[v][i],v);
    }

    if(v != p)
    cout<<p<<" ";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);


    int n; //no of nodes
    cin>>n;

    for(int i=0; i<(n-1); i++)
    {
        int x,y;
        cin>>x>>y;
        gph[x].push_back(y);
        gph[y].push_back(x);
    }

    Eular_Tree_Tour(1,1);

    /*
    input -
    7
    1 2
    1 3
    3 7
    2 4
    2 5
    5 6
    */

    return 0;
}


