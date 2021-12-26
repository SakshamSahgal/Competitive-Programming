#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;



lli nCr(lli n, lli r)
{
    return (n*(n-1)/2);
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    lli n,m;
    cin>>n>>m;
    lli kmin=0;
    lli kmax=0;

    if(n%m == 0)
    {
        kmin = m*(nCr((n/m),2));
    }
    else
    {
        kmin = (n%m)*nCr(((n/m)+1) ,2) + ( m - (n%m) )*(nCr((n/m),2));
    }

    kmax = nCr(n-m+1,2);
    cout<<kmin<<" "<<kmax;
    return 0;
}

