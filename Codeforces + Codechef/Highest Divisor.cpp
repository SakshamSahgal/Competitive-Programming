#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
if(n<10)
      cout<<n;
else
    {
    for(si i=10;i>=1;i--)
        {
            if(n%i == 0)
                {
                cout<<i;
                break;
                }
        }
    }
return 0;
}
