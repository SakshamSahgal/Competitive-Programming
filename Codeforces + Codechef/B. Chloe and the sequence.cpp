#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli fast_Power_without_mod(lli a,lli b)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res)*(a));

        a = ((a)*(a));
        b = b>>1; //b = b/2
    }
    return res;
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    lli n,k;
    cin>>n>>k;

    double x;
    for(lli i=1; i<=n; i++)
    {
        x = ((k*1.0)/fast_Power_without_mod(2,i)) + (0.5);
        if(abs(x-(lli)x) == 0)
            cout<<i<<"\n";
    }
    return 0;
}
