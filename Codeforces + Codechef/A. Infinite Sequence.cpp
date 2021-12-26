#include<iostream>
#include<cmath>
using namespace std;
int main()
{
unsigned long long int x;
cin>>x;
double z = pow(((8*x)+1),0.5);
cout<<<fixed<<setprecision(14)<<z<<" "<<(int)z;
}
