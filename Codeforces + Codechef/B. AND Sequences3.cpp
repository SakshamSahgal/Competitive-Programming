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


lli fact(lli n,lli mod)
{
    lli ans=1;
    for(lli i=n;i>=1;i--)
        ans = (((ans%mod)*(i%mod))%mod);
    return ans;
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
        lli a[n];
        map<lli,lli> freq;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            freq[a[i]]++;
        }

        lli pura_and = a[0];

        for(int i=0;i<n;i++)
            pura_and = a[i]&pura_and;

        lli mod = 1000000007;
        lli ans = freq[pura_and];
        cout<<(((((ans%mod)*((ans-1)%mod))%mod)*(fact(n-2,mod)%mod))%mod)<<"\n";
        t--;
    }
    return 0;
}
