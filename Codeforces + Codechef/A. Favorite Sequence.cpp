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
    usi n;
    cin>>n;
    unsigned int b[n];
    unsigned int a[n];
    for(usi i=0;i<n;i++)
        cin>>b[i];
    usi j =0;
    for(usi i=0;i<n;i+=2,j++)
        a[i] = b[j];
    j = (n-1);
    for(usi i=1;i<=(n-1);i+=2,j--)
        a[i] = b[j];
    //cout<<"\n-------------\n";
    for(usi i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
    //cout<<\n-------------\n";
    }




return 0;
}
