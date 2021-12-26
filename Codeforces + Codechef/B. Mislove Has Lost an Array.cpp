#include<iostream>
#include<cmath>
using namespace std;
int main()
{
long long int n,l,r;
cin>>n>>l>>r;
cout<<(int)((n-l+1) + 2*( pow(2,(l-1)) - 1 ));
cout<<" "<<(int)(pow(2,(r-1))-1+((n-r+1)*2)*pow(2,(r-2)));
return 0;
}
