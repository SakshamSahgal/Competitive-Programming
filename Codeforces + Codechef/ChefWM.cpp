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

void set_printer(set<lli> x)
{

    cout<<"\n--------factors of n------------------\n";
    for(auto i =x.begin();i!=x.end();i++)
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

void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------prime factors of m------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}


vector<pair<lli,lli>> prime_factorisation(lli n)
{
    vector<pair<lli,lli>> p;
    if(n == 1)
        return p;
    else
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0)
            {
                int c=0;
                while(n%i == 0)
                {
                    n=n/i;
                    c++;
                }
                p.push_back({i,c});
            }
        }

        if(n != 1)
            p.push_back({n,1});

        return p;
    }
}


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        if(m == 1)
            cout<<0<<"\n";
        else if(n == 1)
            cout<<1<<"\n";
        else
        {
            set<lli> fn = factor_it(n);
            //set_printer(fn);
            vector<pair<lli,lli>> pfm = prime_factorisation(m);
            //pair_printer(pfm);
            lli ans = 1;
            for(auto i=fn.rbegin();i!=fn.rend();i++)
            {
                if( pfm.size() >= (*i))
                {
                    ans = (*i);
                    break;
                }
            }
            cout<<ans<<"\n";
        }

        t--;
    }
    return 0;
}
