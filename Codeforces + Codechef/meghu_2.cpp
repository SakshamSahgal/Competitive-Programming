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
int n;
cin>>n;
int sum=0;
int x;
while(n!=0)
    {
    x = n%10;
    sum+=x;
    n=n/10;
    }
cout<<sum<<"\n";
return 0;
}

