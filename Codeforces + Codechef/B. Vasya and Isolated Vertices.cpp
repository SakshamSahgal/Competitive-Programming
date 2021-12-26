#include<iostream>
#include<algorithm>
#include<vector>
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
    lli n,m;
    cin>>n>>m;
    if(m == 0)
        cout<<n<<" "<<n<<"\n";
    else
    {
    double d = ((8.0*m)-7.0);
    lli z = n-(2*m);
    if(z<0)
        cout<<"0";
    else
    cout<<z;

    cout<<" "<<n - (int)((3+sqrt(d))/2)<<"\n";
    }
    return 0;
}
