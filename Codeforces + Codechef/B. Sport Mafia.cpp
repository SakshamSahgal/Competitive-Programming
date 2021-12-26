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
    lli n,k;
    cin>>n>>k;
    cout<<setprecision(16)<<((3+2*n) - sqrt( (3+2*n)*(3+2*n) - 4*(n*n + n - 2*k) ))/2.0<<"\n";

    return 0;
}


