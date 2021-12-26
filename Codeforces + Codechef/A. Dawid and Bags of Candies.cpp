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
int a[4];
for(int i=0;i<4;i++)
    cin>>a[i];
sort(a,a+4);

if( ((a[3]+a[0]) == (a[2] + a[1])) || ((a[0] + a[1] + a[2]) == a[3])  || ( a[0] + a[1] == a[2] + a[3] ) )
 cout<<"YES\n";
else
cout<<"NO\n";

return 0;
}

