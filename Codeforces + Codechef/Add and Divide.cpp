#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


lli LCM(lli a,lli b)
{
    return ( (a*b) / (__gcd(a,b)) );
}

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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli a,b,x=0,z=0;
        cin>>a>>b;
        if(a == 1 && b == 1)
            cout<<"YES\n";
        else
        {
            if(b == 1)
                cout<<"NO\n";
            else
            {
                for( lli i = a;;)
                {
                    if(i == 1)
                    {
                        z = 1;
                        break;
                    }
                    lli x = LCM(i,b);
                    if(x == i*b)
                    {
                        z=0;
                        break;
                    }
                    i=x/b;
                }

                if(z == 1)
                    cout<<"YES\n";
                else
                    cout<<"NO\n";
            }

        }

        t--;
    }
    return 0;
}
