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
lli n,x;
cin>>n>>x;
int a[n];
lli sum=0;
for(int i=0;i<n;i++)
    {
      cin>>a[i];
        sum+=a[i];
    }

if( x>= (2*n - 1) )
    {
        if( sum + n - 1 == x )
        cout<<"YES\n";
        else
        cout<<"NO\n";
    }
else
    cout<<"NO\n";
return 0;
}

