#include<iostream>
#include<algorithm>
#include<cstring>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
int main()
{
usi n,k;
cin>>n>>k;
ui a[n];
for(usi i=0;i<n;i++)
    cin>>a[i];
if(k>n)
    cout<<"-1\n";
else
    {
    sort(a,a+n);
    usi nc = n;
    for(usi i=0;i<n;i++)
        {
            if(k == nc)
                {
                cout<<a[i]<<" "<<0<<"\n";
                return 0;
                }
            else
                {
                nc--;
                }
        }
    }



return 0;
}
