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
    //GO_FAST
    lli n;
    cin>>n;
    lli c=0;
    for(int i=1; i<=n; i++)
    {
        vector<pair<lli,lli>> p;
        p = prime_factorisation(i);
        //pair_printer(p);
        if(p.size() == 2)
            c++;
    }
    cout<<c<<"\n";
    return 0;
}
