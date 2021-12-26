#include<iostream>
using namespace std;
unsigned long long power(int a,int b)
{
if(b==0)
    return 1;
if(b==1)
    return a;
unsigned long long temp = power(a,b/2);
unsigned long long res = temp*temp;
res = temp*temp;
if(b%2==1)
    res *=a;
return res;
}


int main()
{
unsigned long long n,m;
cin>>n>>m;
cout<<(2<<(n-1));

return 0;
}
