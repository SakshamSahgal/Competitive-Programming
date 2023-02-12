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

lli fact(lli n,lli p)
{
    lli f = 1;
    for(lli i=1;i<=n;i++)
        f = mod(mod(f,modd)*mod(i,modd),modd);
    return f;
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
        string a,b;
        cin>>a>>b;
        lli x=0;
        lli s=0;
        for(int i=0;i<n;i++)
        {
            if(a[i] != b[i])
                x++;
            else
                s++;
        }
        if(x%2)
            cout<<0<<"\n";
        else
        {
            lli ans = fast_Power(2,s,modd);
            lli nf = fact(x,modd);
            lli sb2f = fact(x/2,modd);

            sb2f = mod(mod(sb2f,modd) * mod(sb2f,modd),modd);
            lli mi = modular_inverse(sb2f,modd);
            ans = mod(mod(ans,modd)*mod(mi,modd),modd);
            ans = mod(mod(ans,modd)*mod(nf,modd),modd);
            cout<<ans<<"\n";
        }
        t--;
    }
    return 0;
}

