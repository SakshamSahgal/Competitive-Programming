#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
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

lli sum(set<lli> f)
{
    lli s=0;
    for(auto i:f)
        s += i;
    return s;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    set<lli> f;
    for(int i=1;;i++)
    {
        cout<<"i = "<<i<<" ";
    f = factor_it(i);
    lli s = sum(f);
    cout<<"s = "<<s<<"\n";
    if(s >= 1000000)
    }
    
    
    return 0;
}

