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
ulli t;
cin>>t;
ulli a[t];
for(ulli i=0;i<t;i++)
		cin>>a[i];
		
sort(a,a+t);

for(ulli i=0;i<t;i++)
		cout<<a[i]<<"\n";
	
return 0;
}
