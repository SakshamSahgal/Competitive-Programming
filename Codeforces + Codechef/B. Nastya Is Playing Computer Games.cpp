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
usi n,k;
int m=0;
cin>>n>>k;
if((n-k)<(k-1))
    m+=(n-k);
else
    m+=(k-1);

m+=(3*n);

cout<<m<<"\n";

return 0;
}
