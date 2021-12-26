#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int is_prime(int n)
    {
    if(n == 1 || n == 0) // 1 and 0 is not a prime number
        return 0;
    else
    {
        for(int i=2; i<=sqrt(n);i++)
        {
            //cout<<"n = "<<n<<"\t"<<"i = "<<i<<"\t"<<"n%i == "<<n%i<<"\t"<<"pow = "<<pow(n,0.5)<<"\n";
                if((n%i) == 0)
                    {
                    return 0;
                    break;
                    }
        }
            return 1;
    }
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
for(int x = 4;;x++)
    {
        if(is_prime(x) == 0)
            {
                if( (x-1)%n == 0 )
                    {
                        cout<<(x-1)/n;
                        goto y;
                    }

            }

    }
y:

return 0;
}
