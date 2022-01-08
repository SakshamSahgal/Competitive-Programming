#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void display(map<lli,set<lli>> g,lli n)
{
    cout<<"\n-------------------\n";
    for(int i=1;i<=n;i++)
    {
        cout<<i<<"-> ";
        for(auto j:g[i])
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}

int main()
{
    //GO_FAST
    map<lli,set<lli>> g;

    lli n;
    cin>>n;

    //m-> no of edges
    for(int i=1;i<=n;i++)
    {
            for(int j=2*i;j<=n;j+=i)
                g[i].insert(j);
    }

    display(g,n);



    return 0;
}
