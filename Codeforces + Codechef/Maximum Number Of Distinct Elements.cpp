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
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<pair<int,int>> v;
        int ans[n];
        int k=0;
        for(int i=0;i<n;i++)
        {
            int x;
            cin>>x;
            v.push_back({x,i});
        }
        sort(v.begin(),v.end());
        for(int i=0;i<n;i++)
            {
                if(v[i].first > k)
                    ans[v[i].second] = k++;
                else
                    ans[v[i].second] = 0;
            }

        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}
