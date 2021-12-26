#include<iostream>
using namespace std;
int main()
{
int n,switchit = 0;
cin>>n;
cout<<"I hate ";
for(int i=1 ;i<n;i++)
    {
    if(switchit == 0)
        {
        cout<<"that I love ";
        switchit = 1;
        }
    else if(switchit == 1)
        {
        cout<<"that I hate ";
        switchit = 0;
        }
    }
cout<<"it ";
return 0;
}
