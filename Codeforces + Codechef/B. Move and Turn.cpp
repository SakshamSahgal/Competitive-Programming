#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int n;
cin>>n;
if(n%2 == 0)
    {
        cout<<((n/2)+1)*((n/2)+1);
    }
else
    {
       cout<<((n/2)+1)*(n - ((n/2) - 1 )) + ((n/2) + 2 )*((n/2) + 1 );
    }
return 0;
}
