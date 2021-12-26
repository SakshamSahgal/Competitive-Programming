#include<iostream>
#include<algorithm>
#include<vector>
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
int t;
cin>>t;
while(t)
    {
    int n,a,b;
    cin>>n>>a>>b;
    cout<<(2*(180+n) - a - b)<<"\n";
    t--;
    }

return 0;
}
