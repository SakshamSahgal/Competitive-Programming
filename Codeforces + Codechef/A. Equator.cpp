#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int n;
cin>>n;
int a[n];
ulli sum=0;
for(int i=0;i<n;i++)
    {
    cin>>a[i];
    sum+=a[i];
    }
ulli mid;
if(sum%2 == 0)
    mid = sum/2;
else
    mid = sum/2 + 1;
sum = 0;
for(int i=0;i<n;i++)
{
    sum+=a[i];
    if(sum>=mid)
    {
        cout<<i+1;
        break;
    }
}
return 0;
}

