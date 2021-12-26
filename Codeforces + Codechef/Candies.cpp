#include<iostream>
#include<cmath>
using namespace std;
int main()
{
int t,n,x,k=2;
cin>>t;
while(t--)
    {
    cin>>n;
    int temp = pow(2,k) - 1;
    while(n%temp != 0)
        {
        k++;
        temp = pow(2,k) - 1;
        }
        x = n/temp;
        cout<<x<<"\n";
        x=0;
        k=2;
    }
return 0;
}
