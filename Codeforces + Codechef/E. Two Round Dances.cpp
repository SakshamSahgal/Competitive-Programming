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

lli npr(lli n,lli r)
{
    lli ans=1;

    for(lli i=n; i>=(n-r+1); i--)
        ans*=i;

    return ans;
}


int main()
{
    GO_FAST
    lli n;
    cin>>n;
    lli x = (npr(n,n/2)*(npr(n/2,n/2)))/((pow((n/2),2))*2);
    cout<<x<<"\n";
    return 0;
}
