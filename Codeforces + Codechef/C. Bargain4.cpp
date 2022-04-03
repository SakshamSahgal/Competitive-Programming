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

lli mod = 1e9 + 7;

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

lli mul_mod(lli a,lli b)
{
    return (a*b)%mod;
}

void add_mod(lli &a,lli b)
{
    a += b;
    if(a >= mod)
        a -= mod;
}

int main()
{
    GO_FAST

    string s;
    cin>>s;
    lli n = s.length();
    lli a[n];
    vector<lli> pow_10(n+1);
    pow_10[0] = 1;


    for(lli i=0; i<n; i++)
        a[i] = (lli)(s[i] - '0');

    lli sum = 0;
    lli ans = 0;
    for(lli i=n-2,k=1; i>=0; i--,k++)
    {
        lli z = k;
        lli p = fast_Power(10,k-1,mod);
        add_mod(sum,mul_mod(z,p));
        add_mod(ans,mul_mod(a[i],sum));
        //cout<<sum<<" ";
    }

    for(lli i=1; i<=n-1; i++)
    {
        lli pre = (i*(i+1))/2;
        lli p = fast_Power(10,n-i-1,mod);
        lli z = mul_mod(a[i],p);
        lli h = mul_mod(z,pre);
        add_mod(ans,h);
    }

    cout<<(ans%mod)<<"\n";

    return 0;
}

