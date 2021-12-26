#include<iostream>
using namespace std;
#define lg long
int main()
{
lg int k,l,m,n,d,countit=0;
cin>>k>>l>>m>>n>>d;
for(lg int i=1;i<=d;i++)
    {
    if((i%k == 0) ||(i%l == 0) || (i%m == 0) || (i%n == 0))
        {
        countit++;
        }
    }
cout<<countit;
return 0;
}
