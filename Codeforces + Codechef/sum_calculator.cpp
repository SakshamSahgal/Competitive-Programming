#include<iostream>
using namespace std;
int main()
{
float arr[30],sum=0;
for(int i=0;i<30;i++)
    {
    cin>>arr[i];
    sum += arr[i];
    }
cout<<"\n"<<sum;
return 0;
}
