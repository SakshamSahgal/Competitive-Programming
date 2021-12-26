#include<iostream>
using namespace std;
int main()
{
int n,k,countit=0;
cin>>n>>k;
int a[n];
for(int i=0;i<n;i++)
    {
    cin>>a[i];
    }

for(int i=0;i<n;i++)
    {
    if((a[i]>= a[k]) && (a[i]>0))
        {
        countit++;
        }
    }
cout<<countit;
return 0;
}
