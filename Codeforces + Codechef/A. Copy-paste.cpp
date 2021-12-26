#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n,k,c=0;
    cin>>n>>k;
    usi a[n];

    for(usi i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    unsigned long int sum = 0;
    for(usi i=1;i<n;i++)
    sum += ((k-a[i])/a[0]);

    cout<<sum<<"\n";
    }
return 0;
}
