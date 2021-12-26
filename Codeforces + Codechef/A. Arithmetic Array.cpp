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
    int n;
    cin>>n;
    int a[n];
    lli sum=0;
    for(int i=0;i<n;i++)
    {
       cin>>a[i];
       sum+=a[i];
    }

    if(sum == n)
        cout<<0<<"\n";
    else if(sum>n)
        cout<<sum-n<<"\n";
    else
        cout<<1<<"\n";

    t--;
    }

return 0;
}
