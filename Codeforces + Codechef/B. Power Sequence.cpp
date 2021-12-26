#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
int main()
{
ui n;
cin>>n;
int a[n];
unsigned long long c = 0;
for(ui i=0;i<n;i++)
    cin>>a[i];
sort(a,a+n);
c+= abs(a[0]-1);
for(ui i=2;i<n;i++)
    {
    c += abs(pow(a[1],i) - a[i]);
    }
cout<<c;
return 0;
}
