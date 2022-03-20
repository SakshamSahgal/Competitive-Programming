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

int main()
{
    GO_FAST
    lli n,q;
    cin>>n>>q;
    lli a[n];
    map<lli,vector<lli>> g;

    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        g[a[i]].push_back(i+1);
    }


    for(int i=0;i<q;i++)
    {
        lli x,k;
        cin>>x>>k;
        if(k <= g[x].size())
            cout<<g[x][k-1]<<"\n";
        else
            cout<<"-1\n";
    }


        return 0;
}
