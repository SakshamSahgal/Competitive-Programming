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


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        set<lli> f = factor_it(n);
        //set_printer(f);
        lli ans = 0;
        lli A;
        for(auto i:f)
        {
            if(i != 1)
            {
                set<lli> y = factor_it(n/i);
                //cout<<"no of factors of = "<<(n/i)<<" is "<<y.size()<<"\n";
                if(y.size() > ans)
                {
                    ans = y.size();
                    A = i;
                }
            }
        }
        cout<<A<<"\n";
        t--;
    }
    return 0;
}
