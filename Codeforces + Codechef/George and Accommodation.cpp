#include<iostream>
using namespace std;
int main()
{
int n,countit=0;
cin>>n;
int p[n];//people living
int q[n];//max people

for(int i=0;i<n;i++)
    {
    cin>>p[i]>>q[i];
    if((q[i] - p[i]) >= 2)
        {
        countit++;
        }
    }
cout<<countit;
return 0;
}
