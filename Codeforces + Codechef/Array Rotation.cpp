#include<iostream>
#include<algorithm>
#include<iomanip>
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
lli a[n];
lli sum=0;
for(int i=0;i<n;i++)
    {
    cin>>a[i];
    sum+=a[i];
    }
int q;
cin>>q;
int x[q];
for(int i=0;i<q;i++)
    {
    cin>>x[i];
    sum+=(sum%1000000007);

    cout<<fixed << setprecision(19)<<(lli)(sum%1000000007)<<"\n";
    }



return 0;
}

