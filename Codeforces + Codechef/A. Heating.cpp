#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi n;
cin>>n;
long int c[n],sum[n];
for(usi i=0;i<n;i++)
    {
    cin>>c[i]>>sum[i];
    if(c[i]>=sum[i])
        cout<<sum[i]<<"\n";
    else
        {
            if(sum[i]%c[i] == 0)
                cout<<c[i]*(sum[i]/c[i])*(sum[i]/c[i])<<"\n";
            else
                {
                long int temp1 = (sum[i]%c[i]);
                long int temp2  = ( c[i] - temp1 );
                cout<< ( ( (sum[i]/c[i]) + 1 )*( (sum[i]/c[i]) + 1 )*temp1 + temp2*(sum[i]/c[i])*(sum[i]/c[i]) )<<"\n";
                }

        }
    }
return 0;
}
