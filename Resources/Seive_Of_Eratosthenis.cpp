#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
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

    for(int i=2; i<=n; i++)
        if(prime[i] == 0)
            cout<<i<<" ";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
seive(100000);

return 0;
}

