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

lli find_sum(lli mid, lli *a,lli n)
{
    lli sum = 0;
    for(int i=0; i<n; i++)
        sum += min(mid,a[i]);
    return sum;
}

int main()
{
    //GO_FAST
    lli n,k;
    cin>>n>>k;
    lli a[n];
    lli sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }
    lli ans=0;
    lli up = 1e18/k;
    lli mid;
    while( up - ans > 1 )
    {
        mid = (ans + up) / 2;
       // cout<<"Trying "<<mid<<"\n";
        if( find_sum(mid,a,n) >= (k*mid) )
            ans = mid;
        else
            up = mid;
       // cout<<"ans = "<<ans<<"\n";

    }

    cout<<ans<<"\n";
    return 0;
}
