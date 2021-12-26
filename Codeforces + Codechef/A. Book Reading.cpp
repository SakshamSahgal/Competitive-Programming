#include<iostream>
#include<algorithm>
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
lli n,t,x;
cin>>n>>t;
lli sum=0;
for(int i=0;i<n;i++)
{
    cin>>x;
    sum+=(86400 - x);
    if(sum >= t)
    {
        cout<<i+1<<"\n";
        break;
    }
}
return 0;
}

