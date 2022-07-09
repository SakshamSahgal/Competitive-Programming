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

lli mod = 998244353;
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


// Utility function to do modular exponentiation.
// It returns (x^y) % p
lli power(lli x,lli y, lli p)
{
    lli res = 1; // Initialize result
    x = x % p; // Update x if it is more than or
    // equal to p
    while (y > 0) {
        // If y is odd, multiply x with result
        if (y & 1)
            res = (res * x) % p;

        // y must be even now
        y = y >> 1; // y = y/2
        x = (x * x) % p;
    }
    return res;
}

// Function to find modular inverse of a under modulo p
// using Fermat's method. Assumption: p is prime
lli modInverse(lli a, lli p)
{
    return power(a, p - 2, p);
}

// Returns n! % p using Wilson's Theorem
lli modFact(lli n, lli p)
{
    // n! % p is 0 if n >= p
    if (p <= n)
        return 0;

    // Initialize result as (p-1)! which is -1 or (p-1)
    lli res = (p - 1);

    // Multiply modulo inverse of all numbers from (n+1)
    // to p
    for (lli i = n + 1; i < p; i++)
        res = (res * modInverse(i, p)) % p;
    return res;
}





// Returns n^(-1) mod p
unsigned long long modInverse(unsigned long long n,
                                            int p)
{
    return power(n, p - 2, p);
}

// Returns nCr % p using Fermat's little
// theorem.
lli nCrModPFermat(lli n,lli r,lli p)
{
    // If n<r, then nCr should return 0
    if (n < r)
        return 0;
    // Base case
    if (r == 0)
        return 1;

    // Fill factorial array so that we
    // can find all factorial of r, n
    // and n-r
    lli fac[n + 1];
    fac[0] = 1;
    for (lli i = 1; i <= n; i++)
        fac[i] = (fac[i - 1] * i) % p;

    return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    lli bb = modFact(n*n,mod);
    cout<<"bb = "<<bb<<"\n";
    lli sub = mul_mod(n*n,modFact((n-1)*(n-1),mod));
    cout<<bb<<sub<<"\n";
    lli sum=0;
    for(lli i=n;i<=(n*n - n - 1);i++)
    {
        lli c1 = nCrModPFermat(i-1,n-1,mod);
        lli c2 = nCrModPFermat(n*n - i + 1,n-1,mod);
        lli z = modFact(n-1,mod);
        z = mul_mod(z,z);
        z = mul_mod(z,c1);
        z = mul_mod(z,c2);
        add_mod(sum,z);
    }
    sum = mul_mod(sum,sub);
    lli ans = (bb - sum)%mod;
    cout<<ans<<"\n";
    return 0;
}
