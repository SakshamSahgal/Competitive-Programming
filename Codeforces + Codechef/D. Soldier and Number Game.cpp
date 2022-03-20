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



vector<bool>is_prime(5000001, true);
vector<lli> prime; //vector that stores all the prime numberes from 2 to N inclusive
lli SPF[5000001]; //array that stores the smallest prime factor of all the numbers from 2 to N inclusive
lli pf[5000001];
void seive_optimised(lli n)
{
    prime.clear();
    is_prime[0] = is_prime[1] = false ;
    for (lli i=2; i<= n; i++)
    {
        if (is_prime[i])
        {
            prime.push_back(i);
            SPF[i] = i;
        }
        for (lli j=0; j < (lli)prime.size() && (i*prime[j]) <= n && prime[j] <= SPF[i]; j++)
        {
            is_prime[(i*prime[j])]=false;
            SPF[i*prime[j]] = prime[j] ;
        }
    }
}

vector<lli> ps;

lli calc_no_of_pf(lli n)
{
    SPF[0]=0;
    SPF[1]=0;
    lli sum=0;
    ps.push_back(0);
    ps.push_back(0);
    for(int i=2;i<=n;i++)
    {
        pf[i] = 1 + pf[(i/SPF[i])];
        sum += pf[i];
        ps.push_back(sum);
    }
}


int main()
{
    GO_FAST
    seive_optimised(5000000);
    calc_no_of_pf(5000000);
    int t;
    cin>>t;
    while(t)
    {
        lli a,b;
        cin>>a>>b;
        if(a == b)
            cout<<pf[a]<<"\n";
        else
            cout<<ps[a] - ps[b]<<"\n";
        t--;
    }
    return 0;
}
