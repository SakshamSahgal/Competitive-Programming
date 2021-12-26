#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
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
int n,r;
cin>>n>>r;
double degree_to_radian = (3.1415926535897932/n);
cout<<setprecision(15)<<(double)(r*sin(degree_to_radian))/(1-sin(degree_to_radian))<<"\n";

return 0;
}


