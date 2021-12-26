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
    lli n,x,k;
    cin>>n>>x>>k;

    if( (x-k)%k == 0 || (x+k-n-1)%k == 0 && (((x+k-n-1)*1.0)/k) < 1)
   cout<<"YES\n";
   else
    cout<<"NO\n";

    t--;
    }

return 0;
}

