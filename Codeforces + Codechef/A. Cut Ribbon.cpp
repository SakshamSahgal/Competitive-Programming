#include<iostream>
#include<algorithm>
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
    int n;
    int a[3];
    cin>>n>>a[0]>>a[1]>>a[2];
    sort(a,a+3);
    usi ans=0;
    if(n%a[0] == 0)
    {
        ans = n/a[0];
    }
    else
    {
        int x = n/a[0];
        int y = n/a[1];
        double z;

        for(; x>=0; x--)
        {
            for(y = n/a[1]; y>=0; y--)
            {
                //z = (n - (a[0]*x) - (a[1]*y) )/(a[2]*1.0);
               // cout<<"checking for x = "<<x<<" y = "<<y<<" z = "<<z<<"\n";
                if( ( n - (a[0]*x) - (a[1]*y) ) >= 0 )
                {
                    if ( ( n - (a[0]*x) - (a[1]*y) )%a[2] == 0  )
                    {
                        z = (n - (a[0]*x) - (a[1]*y) )/a[2];
                        if((x+y+z)> ans)
                            ans = (x+y+z);
                    }
                }
                else
                    continue;


            }

        }
    }
h:
    cout<<ans;
    return 0;
}
