#include<iostream>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
unsigned long long int n;
cin>>n;
unsigned long long int k = pow(2,n);
cout<<fixed<<2*(k-1);
return 0;
}
