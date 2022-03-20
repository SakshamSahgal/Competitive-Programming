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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        map<lli,vector<lli>> g;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            g[a[i]].push_back(i);
        }

        lli maxx = -1;

        for(auto i:g)
        {
            if(i.second.size() >= 2)
            {
               for(int j=0;j<i.second.size()-1;j++)
               {
                   lli l1 = n - i.second[j+1] - i.second[j];
                   lli l2 = i.second[j] + (n - 1 - i.second[j+1]) + 1;
                   maxx = max(maxx,max(l1,l2));
               }
            }
        }
        cout<<maxx<<"\n";

        t--;
    }
    return 0;
}
