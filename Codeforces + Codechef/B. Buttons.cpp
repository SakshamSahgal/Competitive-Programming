#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
int n;
cin>>n;
int sum = ((n*(n+1))/2);
if(n>2)
    {
    for(usi i=(n-1),j=1;i>=2;i--,j++)
        sum += (i-1)*j;
    }
cout<<sum;
return 0;
}
