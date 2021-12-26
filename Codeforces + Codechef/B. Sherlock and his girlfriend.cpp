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

lli prime[100001] = {0}; //0-> prime 1-> not prime

void seive(lli n)
{
    for(int i=2; i*i<=n; i++)
    {
            if(prime[i] == 0)
            {
                for(int j = i*i; j<=n; j+=i)
                    prime[j] = 1;
            }
    }

//for(int i=2; i<=n; i++)
  //      if(prime[i] == 0)
    //        cout<<i<<" ";
}

int main()
{
    GO_FAST
    lli n;
    cin>>n;
    lli ans[n+2];
    seive(n+1);
    set<lli> x;
    for(int i=2;i<=(n+1);i++)
    {
        if(prime[i] == 0)
            {
                ans[i] = 1;
                x.insert(1);
            }
        else
        {
            ans[i] = 2;
            x.insert(2);
        }
    }
    cout<<x.size()<<"\n";
    for(int i=2;i<=(n+1);i++)
        cout<<ans[i]<<" ";
    return 0;
}
