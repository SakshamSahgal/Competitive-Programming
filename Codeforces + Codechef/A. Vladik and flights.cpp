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
int n,a,b;
cin>>n>>a>>b;
string s;
cin>>s;
if(s[a-1] == s[b-1])
   cout<<0<<"\n";
else
cout<<1<<"\n";


return 0;
}

