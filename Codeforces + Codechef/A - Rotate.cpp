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
string s,c;
cin>>s;
c += s[1];
c += s[2];
c += s[0];
cout<<c<<"\n";
return 0;
}

