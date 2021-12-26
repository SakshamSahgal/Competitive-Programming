#include<iostream>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned int n;
cin>>n;
unsigned long long int a[n][2];
for(unsigned int i=0;i<n;i++)
    cin>>a[i][0]>>a[i][1];
unsigned long long int maxi = a[0][0]+a[0][1];

for(unsigned int i=1;i<n;i++)
    {
       if( (a[i][0]+a[i][1]) > maxi)
            maxi = (a[i][0]+a[i][1]);
    }
 cout<<maxi;
return 0;
}
