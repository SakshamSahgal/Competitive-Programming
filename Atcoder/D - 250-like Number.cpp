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
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

lli cube_root(lli n)
{
    lli z=1;

    while(z*z*z <= n)
    {
        if(z*z*z == n)
            return z;
        else
            z++;
    }
    return (z-1);
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    seive_optimised(1000000);
    //cout<<prime.size()<<"\n";

    lli n;
    cin>>n;
    //cout<<prime[prime.size()-1]<<"\n";
    vector<lli> ans;
    for(lli i=0; i<prime.size(); i++)
    {
        if(prime[i] <= 793700)
            ans.push_back(prime[i]);
    }
    //cout<<ans.size()<<"\n";
    lli c=0;
    for(int i=0; i<ans.size(); i++)
    {
         lli clip = cube_root(n/ans[i]);
         //cout<<clip<<"\n";
         if(clip <= ans[i])
            break;
         else
         {
             auto ptr = lower_bound(ans.begin()+i,ans.end(),clip);

             if(ptr == ans.end())
                c += ans.size() - i - 1;
             else
             {
                  lli id = ptr - ans.begin();
                 if(*ptr == clip)
                     c += id - i;
                 else
                    c += id - i - 1;
             }
         }
    }
    cout<<c<<"\n";
    return 0;
}
