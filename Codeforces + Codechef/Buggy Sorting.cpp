#include<iostream>
using namespace std;
int main()
{
short int n;
cin>>n;
if(n == 1 || n == 2)
    cout<<-1;
else
    while(n--)
    cout<<n+1;



return 0;
}
