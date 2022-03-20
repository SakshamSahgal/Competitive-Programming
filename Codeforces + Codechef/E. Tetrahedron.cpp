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

lli dp_next[4];
lli dp_this[4];
void array_printer(lli a[],lli n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
}
const lli mod = 1e9 + 7;
int main()
{
    GO_FAST

    lli n;
    cin>>n;

    for(int i=n+1; i>=1; i--)
    {
        if(i == n+1)
            dp_this[0] = 1;
        else
        {
            dp_this[0] = (dp_next[1]%mod + dp_next[2]%mod + dp_next[3]%mod)%mod;
            dp_this[1] = (dp_next[0]%mod + dp_next[2]%mod + dp_next[3]%mod)%mod;
            dp_this[2] = (dp_next[0]%mod + dp_next[1]%mod + dp_next[3]%mod)%mod;
            dp_this[3] = (dp_next[0]%mod + dp_next[1]%mod + dp_next[2]%mod)%mod;
        }
        //array_printer(dp_this,4);
        dp_next[0] = dp_this[0];
        dp_next[1] = dp_this[1];
        dp_next[2] = dp_this[2];
        dp_next[3] = dp_this[3];
    }
    cout<<dp_next[0]<<"\n";
    return 0;
}
