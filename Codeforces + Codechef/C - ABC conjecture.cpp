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
    //GO_FAST
    lli n;
    cin>>n;
    lli ans=0;

    for(lli a=1;a<=n;a++)
    {
        for(lli b = a;b<=n;b++)
            ans += n/(a*b);
    }

    cout<<ans<<"\n";
    return 0;
}
