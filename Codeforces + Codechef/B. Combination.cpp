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

map<int,vector<int>,greater<int>> graph;
void display()
{
    for(auto i:graph)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int n;
    cin>>n;
    lli c=1;

    for(int i=0; i<n; i++)
    {
        int a,b;
        cin>>a>>b;
        graph[b].push_back(a);
    }

    for(auto i=graph.begin(); i!=graph.end(); i++)
        sort(i->second.begin(),i->second.end(),greater<int>());

    //display();
    lli ans=0;
    for(auto i:graph)
    {
        for(auto j:i.second)
        {
            ans += j;
            c -= 1;
            c += i.first;

            if(c <= 0)
                goto l;
        }
    }
        l:
        cout<<ans<<"\n";
        return 0;
}


