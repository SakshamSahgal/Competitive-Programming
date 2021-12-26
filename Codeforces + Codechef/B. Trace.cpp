#include<iostream>
#include<algorithm>
#include<cmath>
#include <iomanip> //FOR SETPRECISION
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi n;
cin>>n;
usi a[n];
for(usi i=0;i<n;i++)
    cin>>a[i];
sort(a,a+n,greater<int>());
double area=0;
for(usi i=0;i<n;i+=2)
    {
    if(n%2 == 0)
        area += 3.1415926536*( (pow(a[i],2) - pow(a[i+1],2) ) );
    else
        {
            if(i == (n-1))
                 area += 3.1415926536*(pow(a[i],2) );
            else
                area += 3.1415926536*( (pow(a[i],2) - pow(a[i+1],2) ) );
        }
    }
cout<<setprecision(12)<<area<<"\n";
return 0;
}
