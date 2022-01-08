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

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
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

void display(map<lli,vector<lli>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<pair<lli,lli>> pf = prime_factorisation(n);
        //pair_printer(pf);

        lli ans = 0;
        lli A;
        map<lli,vector<lli>> aa;
        lli maxx_power = 0;
        for(auto i:pf)
        {
            maxx_power = max(i.second,maxx_power);
            aa[i.second].push_back(i.first);
        }
        //display(aa);
        cout<<aa[maxx_power][0]<<"\n";
        t--;
    }
    return 0;
}
