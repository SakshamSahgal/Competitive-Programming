#include<iostream>
#include<algorithm>
#include<cmath>
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
double a = (log(n)/log(2));
//cout<<a<<"\n";
cout<<floor(a)+1<<"\n";
return 0;
}

