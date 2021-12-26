#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
unsigned int n;
cin>>n;
unsigned int a[n];
for(unsigned int i=0;i<n;i++)
cin>>a[i];
sort(a,a+n);
long long unsigned int sumx=0;
long long unsigned int sumy =0;
for(unsigned int i=0;i<n;i++)
    {
    if(i<n/2)
        sumx+=a[i];
    else
        sumy+=a[i];
    }
cout<<sumx*sumx + sumy*sumy;

return 0;
}
