#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
usi t,n;
cin>>t;
while(t--)
    {
    cin>>n;
    if(n%2==0)
        {
        for(usi i=n;i>0;i--)
        cout<<i<<" ";
        }
    else
        {
        usi a[n];
        for(usi i=n;i>0;i--)
            a[i-1] = i;
        usi temp = a[(n/2)];
        a[(n/2)] = a[0];
        a[0] = temp;
        for(usi i=n;i>0;i--)
            cout<<a[i-1]<<" ";
        }
    cout<<"\n";
    }
return 0;
}
