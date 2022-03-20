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
        lli n,k;
        cin>>n>>k;
        lli a[n];
        map<lli,lli> x;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            x[ ( k - (a[i])%k )]++;
        }

        if(x[k] == n)
            cout<<0<<"\n";
        else
        {
            lli ans=0;
            for(auto i:x)
            {
                if(i.first!=k)
                    ans = max(ans,(i.first + (i.second-1)*k));
            }

            cout<<ans+1<<"\n";
        }


        t--;
    }
    return 0;
}
