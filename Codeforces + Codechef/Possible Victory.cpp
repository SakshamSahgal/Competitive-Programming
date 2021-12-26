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
int r,o,c;
cin>>r>>o>>c;

if( (c + (20-o)*36 ) > r )
cout<<"YES\n";
else
cout<<"NO\n";
return 0;
}

