#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
usi a[n];
for(usi i=0;i<n;i++)
    cin>>a[i];

for(usi i=0;i<n;i++)
    {
        if( a[(a[(a[i]-1)]-1)] == i+1 )
            {
               cout<<"YES\n";
                goto x;
            }
    }
cout<<"NO\n";
x:
return 0;
}
