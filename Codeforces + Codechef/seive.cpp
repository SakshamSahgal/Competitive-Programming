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
using namespace std;

vector<lli> p;

void seive(lli n)
{
    bool primes[n+1]; //1->prime , 0-> not prime
    memset(primes,1,sizeof(primes));
    for(int i=2; i<=n; i++)
    {
        if(i*i > n)
            break;
        else
        {
            if(primes[i] == 1)
            {
                for(int j=(i*i); j<=n; j+=i)
                        primes[j] = 0;
            }
        }
    }

    for(int i=2; i<=n; i++)
        if(primes[i] == 1)
            p.push_back(i);
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    //GO_FAST
    seive(50);
    vector_printer(p);
    int n;
    cin>>n;
    auto ap = lower_bound(p.begin(),p.end(),n);
    int ind = ap - p.begin();

    if( (*ap) > n)
    cout<<ind - 1<<"\n";
    else
        cout<<ind<<"\n";
    return 0;
}
