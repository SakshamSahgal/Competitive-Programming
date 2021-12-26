#include <bits/stdc++.h>
using namespace std;
int main()
{
unsigned int n;
cin>>n;
int a[n];
int minimum = INT_MAX;
int maximum = INT_MIN;

for(unsigned int i=0;i<n;i++)
    {
    cin>>a[i];

    if(a[i]>maximum)
        maximum = a[i];

    if(a[i]<minimum)
        minimum = a[i];
    }
int maximum_count = 0;
int minimum_count = 0;
//cout<<"Minimum = "<<minimum<<"\n";
//cout<<"Maximum = "<<maximum<<"\n";
for(unsigned int i=0;i<n;i++)
    {
    if(a[i] == maximum)
        maximum_count++;

    if(a[i] == minimum)
        minimum_count++;
    }
if(maximum == minimum)
    {
    cout<<0;
    }
else
cout<<n-maximum_count-minimum_count;

return 0;
}
