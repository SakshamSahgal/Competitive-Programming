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

lli DP[100001];

void DP_printer(lli n)
{
    cout<<"\n----------------------\n";
    for(int i=1;i<=n;i++)
        cout<<DP[i]<<" ";
    cout<<"\n----------------------\n";
}

lli Bottom_up(lli ind,lli *s,lli n)
{
    lli C = 1;
    if(DP[ind] != 0)
        return DP[ind];
    else
    {
        for(int i=2*ind; i<=n; i+=ind)
        {
            if(s[i] > s[ind])
                C = max(C,((lli)1 + Bottom_up(i,s,n)));
        }
    }
    DP[ind] = C;
    return DP[ind];
}


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        memset(DP,0,sizeof(DP));
        lli n;
        cin>>n;
        lli s[n+1];
        s[0] = 0;
        for(int i=1; i<=n; i++)
            cin>>s[i];

        lli ans=1;
        for(int i=1; i<=n; i++)
           DP[i] = Bottom_up(i,s,n);


        for(int i=1; i<=n; i++)
            ans = max(ans,DP[i]);
       // DP_printer(n);
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
