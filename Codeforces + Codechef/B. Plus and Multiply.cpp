#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


lli fast_Power_without_mod(lli a,lli b)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res)*(a));

        a = ((a)*(a));
        b = b>>1; //b = b/2
    }
    return res;
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        lli n,a,b;
        cin>>n>>a>>b;
        if(a!= 1)
        {
            lli x = ceil((log(n)/log(a)));
            //cout<<"x = "<<x<<"\n";
            for(int i=0; i<=x; i++)
            {
                //cout<<"Checking "<<(n-fast_Power_without_mod(a,i))<<" \n";
               if( (n-fast_Power_without_mod(a,i))< 0 )
                break;
                if( (n-fast_Power_without_mod(a,i))%b == 0)
                {
                    cout<<"YES\n";
                    goto j;
                }
            }
            cout<<"NO\n";

        }
        else
        {
            if( (n-1)%b == 0)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
j:
        t--;
    }

    return 0;
}

