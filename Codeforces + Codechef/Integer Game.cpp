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

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin(); i!=x.end(); i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}

set<lli> factor_it(lli n)
{
    set<lli> factors;
    for(lli i=1; i<=sqrt(n); i++)
    {
        if(n%i == 0)
        {
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    return factors;
}

lli mod = 1000000007;

lli fact_calc(lli n)
{
    lli fact = 1;
    for(lli i=1; i<=n; i++)
        fact = ((fact%mod)*(i%mod))%mod;
    return fact;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    //set_printer(h);
    lli n;
    cin>>n;
    //cout<<"factorial = "<<fact_calc(n)<<"\n";

    lli ans[20];
    for(lli i=1;i<=8;i++)
    {
        set<lli> h = factor_it(fact_calc(i));
         ans[i] = h.size();
    }

    ans[9] = 160;
    ans[10] = 270;
    ans[11] = 540;
    ans[12] = 792;
    ans[13] = 1584;
    ans[14] = 2592;
    ans[15] = 4032;
    ans[16] = 5376;
    ans[17] = 10752;
    ans[18] = 14688;
    ans[19] = 29376;

    cout<<ans[n]<<"\n";
    return 0;
}

