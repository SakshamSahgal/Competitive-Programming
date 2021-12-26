#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool prime(int n)
{
    if(n == 1)
        return 0;
    else
    {
        for(int i=2; i<n; i++)
        {
            if(n%i == 0)
                return 0;
        }

        return 1;

    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int j=0;
    int i=2;
    while(j<=10)
    {
        if(prime(i) == 1)
        {
          j++;
          cout<<i<<" ";
        }


    }
    return 0;
}

