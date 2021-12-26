#include<iostream>
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
    unsigned short int n;
    cin>>n;
    short int a[n],b[n];

    for(usi i=0;i<n;i++)
        cin>>a[i];

    for(int i=0;i<n;i+=2)
        {
        b[i] = -1*a[i+1];
        b[i+1] = a[i];
        }


    for(usi i=0;i<n;i++)
    cout<<b[i]<<" ";
    cout<<"\n";
    }

return 0;
}
