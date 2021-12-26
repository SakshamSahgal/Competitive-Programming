#include<iostream>
#include<cmath>
# define usi unsigned short int
using namespace std;
int main()
{
usi t;
cin>>t;
int n;
long long int sum = 0;
while(t--)
    {
    cin>>n;
    for(usi i=1,j=0;i<=n;i++)
        {
            if(i == pow(2,j))
                {
                    sum+= (-1)*i;
                    j++;
                }
            else
                sum+=i;
        }
    cout<<sum<<"\n";
    }

return 0;
}
