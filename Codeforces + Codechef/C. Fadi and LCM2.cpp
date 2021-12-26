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
set<lli> fact;

void factors(lli n)
{
    for(lli i=1; i*i<=n; i++)
    {
        if(n%i == 0)
        {
            fact.insert(i);
            fact.insert(n/i);
        }
    }
}

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin(); i!=x.end(); i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}
int main()
{
    GO_FAST
    lli x;
    cin>>x;
    factors(x);
    //set_printer(fact);
    lli mini = LLONG_MAX;
    lli minia;
    lli minib;
    for(auto i:fact)
    {
        if(  (i*(x/i))/(__gcd(i,(x/i))) ==  x )
        {
            if(mini > max(i,x/i) )
            {
                mini = max(i,x/i);
                minia = i;
                minib = x/i;
            }
        }
    }
    cout<<minia<<" "<<minib<<"\n";
    return 0;
}
