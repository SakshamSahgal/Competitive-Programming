#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
string s;
cin>>s;
int noz=0,noo=0;

for(int i=0;i<n;i++)
{
    if(s[i] == '0')
        noz++;
    else
        noo++;
}
cout<<abs(noz-noo)<<"\n";
return 0;
}
