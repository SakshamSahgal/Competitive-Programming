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


void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void Display(map<lli,vector<lli>> g)
{
    cout<<"\n----------------------\n";

    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n----------------------\n";
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli b[n+1];
        map<lli,vector<lli>> g;
        lli root = -1;
        for(int i=1; i<=n; i++)
        {
            cin>>b[i];
            if(b[i] == i)
                root = i;
            else
                g[b[i]].push_back(i);
        }

        //Display(g);
        lli p[n+1];
        map<pair<lli,lli>,lli> w;

        for(int i=1; i<=n; i++)
            cin>>p[i];

        if(root != -1 && p[1] == root)
        {
            map<lli,lli> dist;
            vector<lli> vv;

            for(int i=1;i<=n;i++)
                dist[i] = INT_MIN;

            dist[root] = 0;

            for(int i=1; i<=n; i++)
            {
                //vector_printer(vv);
                if(i != 1)
                {
                    lli req = dist[p[i-1]] + 1;
                    dist[p[i]] = req;
                    lli parent_dist  = dist[b[p[i]]];
                    if(parent_dist == INT_MIN)
                    {
                        cout<<"-1\n";
                        goto l;
                    }
                    else
                        w[ {p[i],b[p[i]]}] = req - parent_dist;
                }
            }

            for(int i=1; i<=n; i++)
                cout<<w[ {i,b[i]}]<<" ";
            cout<<"\n";
        }
        else
            cout<<"-1\n";


l:
        t--;
    }
    return 0;
}
