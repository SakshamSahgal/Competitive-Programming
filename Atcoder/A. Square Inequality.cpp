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
int a,b,c;
cin>>a>>b>>c;
if( (a*a + b*b) < c*c )
cout<<"Yes\n";
else
cout<<"No\n";
return 0;
}

