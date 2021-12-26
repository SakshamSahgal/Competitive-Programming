#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
long long int n,m;
cin>>n>>m;
long long int a[m];
long long int t=0;
long long int att = 1;
for(ui i=0;i<m;i++)
    {
    cin>>a[i];
    if( (a[i]-att) >= 0 )
        t+=(a[i]-att);
    else
        t+= n + a[i] - att;

    att = a[i];
    }
cout<<t<<"\n";
return 0;
}
