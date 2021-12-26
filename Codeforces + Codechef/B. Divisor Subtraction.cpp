#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli prime[100001] = {0};

void Seive(lli n)
{
    for(lli i=2; i<=n; i++)
    {
        if(i*i>n)
        {
            break;
        }

        if(prime[i] == 0)
        {
            for(int j=i*i; j<=n; j+=i)
            {
                if(prime[j] == 0)
                    prime[j] = 1;
            }
        }
    }
}

lli smallest_prime_factor(lli n)
{
    for(lli i=2; i<=100000; i++)
    {
        if(prime[i] == 0)
        {
            //cout<<"checking "<<i<<"\n";
            if(n%i  == 0)
            {
                return i;
            }
        }
    }
    return n;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli n;
    cin>>n;
    if(n == 0)
        cout<<0;
    else
    {
        Seive(100000);

        lli moves=0;

        while(n!=0)
        {
            lli s = smallest_prime_factor(n);
            //cout<<"spf = "<<s<<"\n";
            if(s == n)
            {
                moves+=1;
                break;
            }

            if(s == 2)
            {
                moves += n/2;
                break;
            }
            else
            {
                n -= s;
                moves++;
            }
        }
        cout<<moves<<"\n";
    }

    return 0;
}

