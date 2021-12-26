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


lli mod = 1000000007;


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
       lli n;
       cin>>n;
       lli ans=1;

       for(lli i=1;i<=n;i++)
       {
           lli x = i;
           while(x%2 == 0)
               x/=2;
           ans = ((ans%mod)*(x%mod))%mod;
       }
        cout<<(ans%mod)<<"\n";
        t--;
    }
    return 0;
}
