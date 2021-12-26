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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int t;
cin>>t;
while(t)
{
    int n,m,k;
    cin>>n>>m>>k;
    if(k == ((n-1) + (m-1)*n ) )
        cout<<"YES\n";
    else
        cout<<"NO\n";
    t--;
}

return 0;
}

