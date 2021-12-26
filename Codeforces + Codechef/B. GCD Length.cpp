#include<iostream>
#include<cmath>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

lli Eular_GCD(lli a,lli b)
{
    lli temp;
x:
    if(a == 0 || b == 0)
    {
        return max(a,b);
    }
    else
    {
        temp = a;
        a = b;
        b = temp%b;
        goto x;
    }
}

int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    usi t;
    cin>>t;
    while(t)
    {
        usi a,b,c;
        cin>>a>>b>>c;
        lli x,y,z;
        for(x = pow(10,(a-1)); x<=(pow(10,a)-1); x++)
        {
                     // cout<<"x = "<<x<<" \n";
          //  cout<<"\n----------------\n";
            for(y = pow(10,(b-1)) ; y<= (pow(10,b)-1) ; y++)
            {
                // cout<<"y = "<<y<<"\n";
                z = Eular_GCD(x,y)/pow(10,c-1);
                if(z != 0 && z<=9)
                {
                    cout<<x<<" "<<y<<"\n";
                    goto x;
                }

            }
           // cout<<"\n----------------\n";
        }
x:
        t--;
    }

    return 0;
}

