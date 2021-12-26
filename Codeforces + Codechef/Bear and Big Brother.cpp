#include<iostream>
using namespace std;
int main()
{
int a,b;
cin>>a>>b;
if(a>=1 && b<=10 && b>=a)
{
    for(int i=1;;i++)
    {
        a*=3;
        b*=2;
    if(a>b)
        {
        cout<<i;
        break;
        }
    }
}
return 0;
}
