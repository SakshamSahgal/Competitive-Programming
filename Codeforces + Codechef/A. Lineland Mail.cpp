#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
using namespace std;
int main()
{
unsigned int n;
cin>>n;
int a[n];
for(unsigned int i=0;i<n;i++)
    cin>>a[i];

cout<<abs(a[1] - a[0])<<" "<<abs(a[n-1]-a[0])<<"\n";

for(unsigned int i=1;i<(n-1);i++)
    {
    if( abs(a[i+1]-a[i]) > abs(a[i]-a[i-1]) )
        cout<<abs(a[i]-a[i-1]) <<" ";
    else
        cout<<abs(a[i+1]-a[i])<<" ";

    cout<<"\n";
    }
cout<<abs(a[n-1]-a[n-2])<<" "<<abs(a[n-1]-a[0])<<"\n";
return 0;
}
