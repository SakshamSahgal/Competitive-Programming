#include<iostream>
#include<algorithm>
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
    lli a,b,n;
    lli c=0;
    cin>>a>>b>>n;
    x:
    if( max(a,b)  > n)
        {
        cout<<c<<"\n";
        goto y;
        }

    else
        {
            if(a<b)
                {
                 a+=b;
                c++;
                }

            else
                {
                  b+=a;
                c++;
                }
        }
    goto x;
    y:
    t--;
    }

return 0;
}

