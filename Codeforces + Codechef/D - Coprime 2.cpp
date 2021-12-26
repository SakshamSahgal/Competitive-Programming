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

set<lli> factor_it(lli n)
{
    set<lli> factors;
    for(lli i=2; i<=sqrt(n); i++)
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
    int n,m;
    cin>>n>>m;
    set<lli> a;
    int ans[100002];
    memset(ans,-1,sizeof(ans)); //0 -> katta
    for(lli i=0; i<n; i++)
    {
        lli x;
        cin>>x;
        a.insert(x);
    }

    for(auto i:a)
    {
        //cout<<"for "<<i<<"\n";
        if(i > 1)
        {
            ans[i] = 0;
            set<lli> f = factor_it(i);
            for(auto j:f)
            {
                //cout<<"factors = "<<j<<"\n";
                if(ans[j] != 0)
                {
                    for(int k=j;k<=m;k+=j)
                        ans[k] = 0;
                }
            }
        }
    }
    set<lli> ss;
    for(int i=1; i<=m; i++)
    {
        if(ans[i] == -1)
            ss.insert(i);
    }

    cout<<ss.size()<<"\n";
    for(auto i:ss)
        cout<<i<<"\n";

    return 0;
}
