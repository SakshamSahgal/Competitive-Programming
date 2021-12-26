#include<iostream>
#include<algorithm>
#include<iomanip>
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
    usi t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        if(n%2 == 0)
            cout<<fixed<<setprecision(20)<<(n/2)<<" "<<fixed<<setprecision(20)<<(n/2)<<"\n";
        else
        {
            lli a=1,b;

            for(lli i=2;i<=floor(pow(n,0.5)); i++)
            {
                if(n%i == 0)
                    {
                        a = n/i;
                        break;
                    }
            }
            b = n-a;
            cout<<fixed<<setprecision(20)<<a<<" "<<fixed<<setprecision(20)<<b<<"\n";
        }
        x:
        t--;
    }
    return 0;
}
