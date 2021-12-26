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
int n,m,a,b;
cin>>n>>m>>a>>b;
if( a > (b/m) )
    {
        if( (n%m)*a > b )
            cout<<(n/m)*b + b;
        else
            cout<<(n/m)*b + (n%m)*a;
    }

else
    cout<<a*n;

return 0;
}
