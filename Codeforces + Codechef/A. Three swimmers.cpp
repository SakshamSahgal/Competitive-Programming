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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t)
    {
        lli p,a,b,c;
        cin>>p>>a>>b>>c;
       lli x,y,z;

        x = ceil((p*1.0)/a);
        y = ceil((p*1.0)/b);
        z = ceil((p*1.0)/c);

        cout<<min( (x*a-p),min(  (y*b-p), (z*c-p) ))<<"\n";

      //  cout<<ceil(((p+a)*1.0)/a)<<" "<<ceil(((p+b)*1.0)/b)<<" "<<ceil(((p+c)*1.0)/c)<<"\n";

        t--;
    }

    return 0;
}

