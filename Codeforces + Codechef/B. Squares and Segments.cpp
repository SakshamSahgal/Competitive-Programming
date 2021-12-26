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
    lli n;
    cin>>n;
    double a = sqrt(n);
    double b = sqrt(n-1);
    if((a -(int)a) == 0)
        cout<<2*a<<"\n";
    else if( (b-(int)b) == 0 )
        cout<<2*b+1<<"\n";
    else
    {
        for(lli x=n-1; x>=0; x--)
        {
            double c = sqrt(x);
            if((c-(int)c) == 0)
            {
                if( (n - x)>=1 && (n-x)<=(sqrt(x)) )
                    cout<<2*c + 1<<"\n";
                else
                    cout<<2*c+2<<"\n";
            break;
            }

        }
    }
    return 0;
}


