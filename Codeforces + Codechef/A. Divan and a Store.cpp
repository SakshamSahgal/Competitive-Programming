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
        lli n,l,r,k;
        cin>>n>>l>>r>>k;
        lli a[n];
        vector<lli> ok;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(a[i] >= l && a[i] <= r)
                ok.push_back(a[i]);
        }

        lli x = 0;
        sort(ok.begin(),ok.end());
        for(auto i:ok)
        {
            if(k - i >= 0)
            {
                k-=i;
                x++;
            }
            else
                break;
        }
        cout<<x<<"\n";
        t--;
    }
    return 0;
}
