#include<iostream>
#define ui unsigned int
using namespace std;
int main()
{

ui t;
cin>>t;
while(t--)
    {
    ui n,k;
    cin>>n>>k;
    if(k>=n)
        {
        cout<<(k/n)<<"\n";
        }
    else
        cout<<"0\n";
    }

return 0;
}
