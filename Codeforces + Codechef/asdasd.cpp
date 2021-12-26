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
    lli x,y;
    cin>>x>>y;
    if( x < y || y < 0)
        cout<<"Not Reachable\n";
    else
    {
        lli ans = 0;
        ans += y;
        ans += abs(y - x);
        cout<<ans<<"\n";

    }
    return 0;
}
