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
int b[n];
lli ora=0;
lli orb=0;
for(int i=0;i<n;i++)
    {
    cin>>a[i];
    if(i>0)
        ora = ora|a[i];
    else
        ora = a[0];
    }
for(int i=0;i<n;i++)
    {
    cin>>b[i];
    if(i>0)
        orb = orb|b[i];
    else
        orb = b[0];
    }
cout<<ora+orb<<"\n";
return 0;
}

