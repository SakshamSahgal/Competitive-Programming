#include<iostream>
using namespace std;
int main()
{
int n,k,w;
cin>>k>>n>>w;

if((((k*(w*(w+1)))/2) - n)>0)
    {
    cout<<(((k*(w*(w+1)))/2) - n);
    }
else
    {
    cout<<"0";
    }

return 0;
}
