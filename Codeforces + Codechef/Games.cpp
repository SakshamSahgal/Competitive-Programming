#include<iostream>
using namespace std;
int main()
{
short int n;
cin>>n;
short int h[n],a[n],counter=0;
for(int i=0;i<n;i++)
    {
    cin>>h[i]>>a[i];
    }
for(int i=0;i<n;i++)
    {
    for(int j=0;j<n;j++)
        {
        if(h[i] == a[j] && j != i)
            {
                counter++;
            }
        }

    }
cout<<counter;
return 0;
}
