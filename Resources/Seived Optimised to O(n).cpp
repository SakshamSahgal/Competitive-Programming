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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}


map<lli,lli> prime_factorisation(lli n) //this number returns prime factorisation of a number n in log(n) it uses precalculated spf
{
    SPF[1]=1;
    map<lli,lli> pf;//no,power
    while(n!=1)
    {
        pf[SPF[n]]++;
        n = n/SPF[n];
    }
    return pf;
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        seive_optimised(n);
        //vector_printer(prime);
        cout<<"\nsize = "<<prime.size()<<"\n";
        lli x;
        cout<<"Enter a no btw 1 and "<<n<<" to find its prime factorisation \n";
        cin>>x;
        cout<<"Prime factorisation of "<<x<<"in log n time = ";Map_printer(prime_factorisation(x));
        t--;
    }
    return 0;
}
