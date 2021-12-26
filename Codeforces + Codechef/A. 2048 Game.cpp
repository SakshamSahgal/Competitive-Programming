#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
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
    ulli sum = 0;
    bool found = 0;
    ulli a[n];
    for(usi i=0;i<n;i++)
        {
        cin>>a[i];
        if(a[i] == 2048)
            found = 1;
        if(a[i]<2048)
            {
            sum+=a[i];
            if(sum >=2048)
                found = 1;
            }
        }
        if(found == 1)
            cout<<"YES\n";
        else
             cout<<"NO\n";
    }

return 0;
}
