#include<iostream>
using namespace std;

int is_prime(int n)
{
if(n == 1)
    {
    return 0;
    }
else
    {
    for(int i=2;i<=(n/2);i++)
        {
            if(n%i == 0)
                {
                return 0;
                }
        }
    return 1;
    }
}

int main()
{
int n;
cin>>n;
for(int i=1;i<n;i++)
    {
    if(is_prime(i) == 0 && is_prime((n-i)) == 0 && i!=1)
        {
        cout<<i<<" "<<(n-i);
        break;
        }
    }
return 0;
}
