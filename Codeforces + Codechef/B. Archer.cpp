#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<iomanip>
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

    double a,b,c,d;
    cin>>a>>b>>c>>d;
    cout<<setprecision(10)<<((a/b)/( 1 - (1-a/b)*(1-c/d) ))<<"\n";
    return 0;
}

