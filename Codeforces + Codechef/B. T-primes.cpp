#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int is_prime(lli n)
{
    if(n == 1) // 1 is not a prime number
    {
        return 0;
    }
    else
    {
        for(lli i=2; i*i<=n; i++)
        {
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
    int n;
    cin>>n;
    lli a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        double x = pow(a[i],0.5);

        if( abs( x - (int)x )  == 0 && is_prime((int)x) == 1)
        cout<<"YES\n";
        else
        cout<<"NO\n";

        }
    return 0;
}
