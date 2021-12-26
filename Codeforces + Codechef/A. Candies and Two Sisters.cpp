#include<iostream>
using namespace std;
int main()
{
short int t;
int n,i;
cin>>t;
while(t--)
    {
    i=0;
    cin>>n;
    if(n<=2)
        {
        cout<<"0\n";
        }
    else
        {
                if(n%2 == 0)
                    {
                       cout<<((n/2) - 1)<<"\n";
                    }
                else
                    {
                        cout<<(n/2)<<"\n";
                    }
        }
    }
return 0;
}
