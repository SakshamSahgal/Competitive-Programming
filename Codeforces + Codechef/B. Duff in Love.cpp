#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

bool lovely_number(lli n)
{
    if( sqrt(n) - (int)sqrt(n) )
        return 0;

    for(lli i=2;i<=sqrt(n);i++)
    {
        if( n%(i*i) == 0)
            return 0;
    }
return 1;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    //lli n;
    //cin>>n;
    for(int i=1;i<=100;i++)
    {
        if(lovely_number(i) == 1)
            cout<<i<<" ";
    }


    return 0;
}

