#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;
vector<lli> testt[200001];
int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[200025];
        lli dp[20025];
        for(lli i=1; i<=n; i++)
            cin>>a[i];
        for(lli i=1; i<=n; i++)
        {
            int l=i,r=a[i]+i;
            if(r<=n)
                testt[l].push_back(r);
            l=i-a[i],r=i;
            if(l>=1)
                testt[l].push_back(r);
        }
        dp[1]=1;
        for(int i=1; i<=n; ++i)
        {
            if(!dp[i]) continue;
            for(int j:testt[i]) dp[j+1]=true;
        }
        cout << (dp[n+1]?"YES":"NO") << endl;
        t--;
    }
    return 0;
}

