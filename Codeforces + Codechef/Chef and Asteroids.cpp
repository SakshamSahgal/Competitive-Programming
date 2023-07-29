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


lli modd = 1e9+7;

lli fast_Power(lli a,lli b,lli n) //binary exponentiation (log b)
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

lli mod(lli a,lli b)
{
    lli ret = a % b;
    if (ret < 0)
        ret += b;
    return ret;
}

lli modular_inverse(lli x,lli p) //x ka inverse under mod p(must be prime) //O(log(p-2))
{
    lli z = fast_Power(x,p-2,p); //log(p-2)
    z = mod(z,modd);
    return z;
}




int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli fact[100003] = {0};
    fact[0] = 1;
    fact[1] = 1;

    for(lli i=2; i<=1e5+1; i++)
        fact[i] = mod((i%modd)*fact[i-1]%modd,modd);

    lli n;
    cin>>n;
    vector<pll> v(n);
    map<lli,lli> f;
    for(int i=0; i<n; i++)
    {
        cin>>v[i].first>>v[i].second;
        f[v[i].first]++;
    }

    lli num=1;

    for(auto i:f)
    {
       // cout<<i.second<<"\n";
        lli p = fact[i.second];
        num = mod((num%modd)*(p%modd),modd);
    }

    //cout<<num<<"\n";

    lli den = fact[n];

    lli ans = modular_inverse(den,modd);
    ans = ((ans%modd)*(num%modd))%modd;
    cout<<ans<<"\n";
    return 0;
}

