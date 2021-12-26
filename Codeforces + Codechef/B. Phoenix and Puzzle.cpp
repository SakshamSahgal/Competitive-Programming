#include<iostream>
#include<cmath>
#include<algorithm>
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
int t;
cin>>t;
while(t)
{
    lli n;
    cin>>n;
    double y = log(n)/log(2);
    if( n!= 1 && abs(y - int(y)) == 0 )
        cout<<"YES\n";
    else
    {
        for(lli i=1;i<=32000;i++)
            {
                if( (4*i*i) == n  || (2*i*i) == n)
                    {
                        cout<<"YES\n";
                        goto h;
                    }
            }
            cout<<"NO\n";
    }
h:
t--;
}
return 0;
}

