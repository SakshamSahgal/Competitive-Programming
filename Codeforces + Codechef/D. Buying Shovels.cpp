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
    cout<<"\n---------------------------\n";
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

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;

        set<lli> f = factor_it(n);
        //set_printer(f);

        for(auto i=f.rbegin();i!=f.rend();i++)
        {
            if( *i <= k)
            {
                cout<<(n/(*i))<<"\n";
                break;
            }
        }

        t--;
    }
    return 0;
}
