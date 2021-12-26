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
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cout<<"Enter n: ";
        cin>>n;
        cout<<fact(n,1000000007)<<"\n";

        t--;
    }
    return 0;
}
