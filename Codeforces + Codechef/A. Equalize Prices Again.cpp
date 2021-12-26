#include<iostream>
using namespace std;
#include<cmath>
#define usi unsigned short int
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi q;
cin>>q;
while(q--)
    {
    usi n;
    cin>>n;
    unsigned int a[n];
    int sum=0;
    for(unsigned int i=0;i<n;i++)
        {
        cin>>a[i];
        sum+=a[i];
        }
    //cout<<"sum = "<<sum<<" n = "<<n<<"\n";
    cout<<(sum+n-1)/n<<"\n";
    }

return 0;
}
