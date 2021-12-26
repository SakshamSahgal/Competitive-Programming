#include<iostream>
using namespace std;
#define lg long

int main()
{
lg int k,l,m,n,d,countk=1,countl=1,countm=1,countn=1,counter=0,checked_k=0,checked_l=0,checked_m=0,checked_n=0;
int checked=0;
cin>>k>>l>>m>>n>>d;
for(lg int i=0;i<d;i++)
    {
    checked = 0;
    if(countk<=d)
        {
        checked_k = countk;
        }
    if(countl<=d)
        {
        checked_l = countl;
        }
    if(countm<=d)
        {
        checked_m = countm;
        }
    if(countn<=d)
        {
        checked_n = countn;
        }
         if(checked_k == i || checked_l == i ||checked_m == i || checked_n == i)
            {
                counter++;
            }
        countk+=k;
        countl+=l;
        countm+=m;
        countn+=n;
    }
cout<<counter;
return 0;
}
