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

lli mod = 1e9+7;

lli fast_Power(lli a,lli b,lli n)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res%n)*(a%n))%n;

        a = ((a%n)*(a%n))%n;
        b = b>>1; //b = b/2
    }
    return res;
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
        lli n,k;
        cin>>n>>k;
        lli a[n];
        map<lli,lli> f;
        set<lli> d;
        lli ans = fast_Power(2,n,mod);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            a[i] = a[i]%k;
            d.insert(a[i]);
            f[a[i]]++;
        }

        /*
        for(auto i:d)
            cout<<i<<" ";
        cout<<"\n"; */

        for(auto i:d)
        {
            if(i == k-i)
            {
                lli f1 = (fast_Power((lli)2,f[i],mod) - (lli)1%mod - f[i]%mod)%mod;
                lli f2 = fast_Power((lli)2,n - f[i],mod);
                ans = ((ans%mod) - ((f1%mod)*(f2%mod))%mod)%mod;
                f[i] = 0;
            }
            else
            {
                if(f[i] != 0 && f[k-i] != 0)
                {
                    lli f1 = (fast_Power((lli)2,f[i],mod) - (lli)1)%mod;
                    lli f2 = (fast_Power((lli)2,f[k-i],mod) - (lli)1)%mod;
                    lli f3 = fast_Power((lli)2,n - f[i] - f[k-i],mod);
                    ans = (ans%mod - (((f1%mod)*(f2%mod))%mod)*(f3%mod))%mod;
                    f[i] = 0;
                    f[k-i] = 0;
                }
            }
        }

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
