#include<iostream>
using namespace std;
int main()
{
int m,n;
cin>>m>>n;
if(m>=1 && n>=m && n<=16)
    {
    if(n%2 == 0)
        {
        cout<<(n/2)*m;
        }
    else
        {
            cout<<(m/2)+(n/2)*m;
        }
    }
return 0;
}
