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
        vector<pair<int,int>> v;
        for(int i=0; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            v.push_back({x,y});
        }

        sort(v.begin(),v.end());

        int ttleft=-1;
        int btright=-1;

        for(int i=0; i<n-1; i++)
        {
            if( v[i].second - v[i+1].second == 1 )
                ttleft = v[i+1].second;
            else
                break;
        }

        for(int i=n-1;i>0;i--)
        {
           if(v[i-1].second - v[i].second == 1)
               btright = v[i-1].second;
            else
                break;
        }

        if(ttleft == 1 || btright == n)
            cout<<"NO\n";
        else
            cout<<"YES\n";
        t--;
    }
    return 0;
}
