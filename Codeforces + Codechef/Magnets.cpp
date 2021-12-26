#include<iostream>
using namespace std;
#define lg long
int main()
{
lg int n;
cin>>n;
int a[n],count_it=1;
for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }
for(int i=0;i<n-1;i++)
    {
    if(a[i] != a[i+1])
        {
        count_it++;
        }
    }
cout<<count_it;
return 0;
}
