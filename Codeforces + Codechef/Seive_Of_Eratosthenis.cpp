#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void Prime_Printer(lli n)
{
bool prime[n+1] = {0};
for(lli i=2;i<=n;i++)
    {
        if(prime[i] == 0)
            {
                for(int j=i*i;j<=n;j+=i)
                    {
                        if(prime[j] == 0)
                            prime[j] = 1;
                    }
            }

    }

    for(lli i=2;i<=n;i++)
        if(prime[i] == 0)
            cout<<i<<" ";
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
Prime_Printer(123);

return 0;
}

