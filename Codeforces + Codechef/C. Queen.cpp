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

struct pc
{
    int parent;
    int c;
};

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
    //GO_FAST
    int n;
    cin>>n;
    pc a[n+1];
    map<int,vector<int>> g;
    vector<int> bad;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i].parent>>a[i].c;

        if(a[i].parent != -1)
        {
            if(a[i].c == 1)
                bad.push_back(i);
            g[a[i].parent].push_back(i);
        }
    }
    //Display(g);
    bool atleast_one_found=0;
    for(auto i:bad)
    {
        //cout<<"Checking for "<<i<<"\n";
        bool good_child_found=0;
        for(auto j:g[i])
        {
            if(a[j].c == 0)
            {
                good_child_found = 1;
                break;
            }
        }

        if(good_child_found == 0)
        {
            atleast_one_found = 1;
            //cout<<"No good child found for "<<i<<"\n";
            cout<<i<<" ";
            auto ptr = find(g[a[i].parent].begin(),g[a[i].parent].end(),i);
            if(ptr != g[a[i].parent].end())
                g[a[i].parent].erase(ptr);

            for(auto j:g[i])
            {
                a[j].parent = a[i].parent;
                g[a[i].parent].push_back(j);
            }

            g[i].clear();
        }
        //Display(g);
    }

    if(atleast_one_found == 0)
        cout<<"-1\n";
    return 0;
}
