#include<iostream>
using namespace std;
int main()
{
int n,m;
cin>>n>>m;
if(n>m)
    {
    cout<<m<<" ";
    if((n-m)%2 == 0)
        {
        cout<<((n-m)/2);
        }
    else
        {
        cout<<((n-m-1)/2);
        }
    }
else
    {
    cout<<n<<" ";
    if((m-n)%2 == 0)
        {
        cout<<((m-n)/2);
        }
    else
        {
        cout<<((m-n-1)/2);
        }
    }
return 0;
}
