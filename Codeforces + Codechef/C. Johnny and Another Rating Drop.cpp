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


lli nod(lli n)
{
    for(lli i=1;i<=60;i++)
    {
        lli d = powl(2,i) - 1;
        if(n <= d)
            return i;
    }
}

int main()
{
    GO_FAST
    lli t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli ans = 0;
        lli d = nod(n);
        //cout<<d<<"\n";
        for(lli i=0;i<d;i++)
            ans += (n>>i);

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
