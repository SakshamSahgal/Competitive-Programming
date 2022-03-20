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

const lli mod = 1e9+7;

lli fast_Power(lli a,lli b,lli n)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res%n)*(a%n))%n;

        a = ((a%n)*(a%n))%n;
        b = b>>1; //b = b/2
    }
    return res;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli ans=0;
        lli z = 0;
        for(int i=0;i<m;i++)
        {
            lli l,r,x;
            cin>>l>>r>>x;
            z = z|x;
        }
       // cout<<z<<"\n";
        for(int i=0;i<=60;i++)
        {
            if(((z>>i)%2))
                ans = ( ans%mod + (fast_Power(2,(n-1+i),mod))%mod )%mod;
        }
        cout<<(ans%mod)<<"\n";
        t--;
    }
    return 0;
}
