#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define lli long long int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
long long int a[7];
long long int f[7];
for(lli i=0;i<7;i++)
    cin>>a[i];
for(lli i=0;i<7;i++)
    cin>>f[i];
lli sum=0;
for(lli i=0;i<7;i++)
    sum+= abs(a[i]-f[i]);
cout<<sum;
return 0;
}
