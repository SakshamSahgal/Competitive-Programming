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

lli is_set(lli n,lli r)
{
    lli ans = (n>>r)%2;
    return ans;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        map<lli,lli> f;
        for(lli i=0;i<n;i++)
        {
            cin>>a[i];
            for(lli j=0;j<=20;j++)
                f[j] += is_set(a[i],j);
        }

        for(lli i=0;i<=20;i++)
        {
            if(f[i]%2 == 1 && (n - f[i])%2 == 1)
            {
                cout<<"NO\n";
                goto l;
            }
        }

        cout<<"YES\n";

        l:
        t--;
    }
    return 0;
}

