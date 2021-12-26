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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
lli t;
cin>>t;
while(t)
{
lli a,b;
cin>>a>>b;
if(a%2 == 1 && (b&(b-1)) == 0)
    cout<<"Yes\n";
else
    cout<<"No\n";
t--;
}
return 0;
}
