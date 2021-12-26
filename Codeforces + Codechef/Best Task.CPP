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
string s;
cin>>s;
int n = (s[s.size()-2]-48)*10 + (s[s.size()-1]-48);
if(n%4 == 0)
    cout<<4;
else
    cout<<0;
return 0;
}

