#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int sum_of_dig(lli n)
{
    int sum=0;
    int nod=0;

    while(n!=0)
    {
        sum+=n%10;
        n=n/10;
    }
    return sum;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    lli a;
    cin>>a;
g:
    lli x = sum_of_dig(a);
    if(x>=10)
    {
        a = x;
        goto g;
    }
    cout<<x<<"\n";

    return 0;
}
