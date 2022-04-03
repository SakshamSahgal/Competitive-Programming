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

lli mod = 1e9 + 7;

int main()
{
        GO_FAST
.
        lli n;
        string s;
        cin>>s;
        n = s.length();
        lli a[n];
        lli dp_f[n];
        lli dp_b[n];
        dp_f[n-1] = 0;
        dp_b[0] = 0;
        lli x[n];
        lli to_add=0;

        for(lli i=0; i<n; i++)
        {
            a[i] = (lli)(s[i] - '0');
            x[i] = ( (a[i]%mod) * (fast_Power(10,n-i-1,mod)%mod) )%mod;
        }

        for(int i=n-2; i>=0; i--)
        {
            dp_f[i] = ((x[i+1]%mod) + (dp_f[i+1]%mod) + (to_add%mod))%mod;
            to_add = ( (to_add%mod) + x[i+1]%mod )%mod;
        }


        to_add = 0;
        for(lli i=1;i<n;i++)
        {
            lli g = (( (fast_Power(10,n-i,mod)%mod) - 1)/9)%mod;
            lli h = (a[i-1]%mod)*(g%mod);
            dp_b[i] = (h%mod + dp_b[i-1]%mod - to_add%mod )%mod;
            to_add = ( (to_add%mod) + a[i-1]%mod )%mod;
        }

        array_printer(dp_f,n);
        array_printer(dp_b,n);
        lli ans=0;

        for(lli i=0;i<n;i++)
            ans = ( (ans%mod) + (dp_b[i]%mod) + (dp_f[i]%mod))%mod;

        cout<<ans<<"\n";
    return 0;
}
