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
    for(int i=2; i<=n; i++)
    {
        if(i*i > n)
            break;
        else
        {
            if(prime[i] == 0)
            {
                for(int j = i*i; j<=n; j+=i)
                    prime[j] = 1;
            }
        }
    }
    //for(int i=2; i<=n; i++)
    // if(prime[i] == 0)
    //  cout<<i<<" ";
}

int main()
{
    GO_FAST

    int n;
    cin>>n;
    seive(n);
    int c=0;
    int g=0;
    for(int i=2; i<=n; i++)
    {
        if(prime[i] == 0)
        {
            cout<<(++c)<<" ";
            g=0;
        }
        else
            cout<<(++g)<<" ";
    }
    return 0;
}
