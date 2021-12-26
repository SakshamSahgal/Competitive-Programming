#include<iostream>
using namespace std;
int main()
{
short int n,k;
cin>>n>>k;
int c = 1;
while( (((5*c*(c+1))/2) <=  (240-k) ) && (c<=n) )
    {
    c++;
    }
cout<<(c-1);
return 0;
}
