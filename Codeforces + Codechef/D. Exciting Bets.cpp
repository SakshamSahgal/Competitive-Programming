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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli a,b;
        cin>>a>>b;
        if(a == b)
            cout<<0<<" "<<0<<"\n";
        else
        {
            lli ans = max(a,b) - min(a,b);
            lli moves = min(min(a,b)%ans , ans - min(a,b)%ans);
            cout<<ans<<" "<<moves<<"\n";
        }
        t--;
    }
    return 0;
}
