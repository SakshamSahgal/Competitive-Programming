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
ui n;
cin>>n;
if(n%2 == 0)
    cout<<(n/2)-1;
else
    cout<<n/2;

return 0;
}
