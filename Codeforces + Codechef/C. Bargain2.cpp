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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

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

lli mod = 1e9+7;

int main()
{
    //GO_FAST

        string s;
        cin>>s;
        lli to_subs=0;
        lli n = s.length();
        for(lli i=n-1,k=0; i>=1; i--,k++)
        {
            lli dig = (s[i] - '0');
            lli a = fast_Power(10,k,mod)%mod;
            to_subs = ( to_subs%mod + ( (dig%mod)*(a%mod) )%mod )%mod;
        }

        lli bs = 0;

        for(lli i=n-1,k=0; i>=1; i--,k++)
        {
            lli dig = (s[i] - '0');
            lli a = fast_Power(10,k,mod)%mod;
            lli x = ((a%mod)*(dig%mod))%mod;
            lli y = ( (x%mod) * (i%mod) )%mod;
            bs = ((bs%mod) + (y%mod))%mod;
        }

        lli suff = 0;
        lli pref = 0;
        lli ans=0;
        lli dp[n];
        dp[0] = 0;
        for(lli i=0; i<n; i++)
        {
            suff = (suff%mod + bs%mod)%mod;
            cout<<"i = "<<i<<" adding = "<<bs<<"\n";
            if(i >= 1)
            {
                lli dig = (s[i] - '0');
                lli last_dig = s[i-1] - '0';
                lli k = n - i - 1;
                lli a = fast_Power(10,k,mod)%mod;
                lli x = ((a%mod)*(dig%mod))%mod;
                to_subs = (to_subs%mod - x%mod)%mod;

                lli pow = fast_Power(10,n-i-1,mod)%mod;
                lli g = (((lli)10*((pow%mod) - 1))%mod)/9;
                dp[i] = (((last_dig%mod)*(g%mod))%mod + ((10%mod)*(dp[i-1]%mod))%mod)%mod;
                pref = (pref%mod + dp[i]%mod)%mod;
            }
            bs = (bs%mod - (to_subs%mod))%mod;
        }

        array_printer(dp,n);

        ans = ( (pref%mod) + (suff%mod) )%mod;
        cout<<ans<<"\n";


    return 0;
}

