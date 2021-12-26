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
usi s=0;
usi x;
for(usi i=0;i<n;i++)
    {
    cin>>x;
    s+=x;
    }
usi c=0;
for(usi i=1;i<=5;i++)
    {
        if( (s+i-1)%(n+1) != 0 )
            c++;
    }
cout<<c;
return 0;
}
