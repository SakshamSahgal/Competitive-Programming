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
        lli noz=0;
        lli noo=0;
        bool all_same = 1;
        bool all_odd=1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];

            if(a[i]%2 == 0)
                all_odd = 0;

            if(a[i] != a[0])
                all_same = 0;

            if(a[i] == 0)
                noz++;
            if(a[i] == 1)
                noo++;
        }
        lli mod = 1000000007;
        if(all_same == 1)
           cout<<fact(n,mod)<<"\n";
        else if(noz >= 2)
            cout<<((((noz%mod)*((noz-1)%mod))%mod)*(fact(n-2,mod)))%mod<<"\n";
        else if(noo >= 2 && all_odd == 1)
            cout<<((((noo%mod)*((noo-1)%mod))%mod)*(fact(n-2,mod)))%mod<<"\n";
        else
            cout<<0<<"\n";
        t--;
    }
    return 0;
}
