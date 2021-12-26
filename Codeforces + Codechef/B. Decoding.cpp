#include<iostream>
#include<cmath>
#define usi unsigned short int
using namespace std;
int main()
{
usi n;
cin>>n;
char a[n];
char b[n];
int stp;
if(n%2 == 1)
    {
        stp = n/2;
        for(usi i=0;i<n;i++)
        {
        cin>>a[i];

            if(i == 0)
                b[stp] = a[i];
            else if(i%2 == 1)
                {
                stp -= i;
                b[stp] = a[i];
                }
            else if(i%2 == 0)
                {
                stp += i;
                b[stp] = a[i];
                }
        }
    }
else
    {
        stp = (n/2) - 1;
        for(usi i=0;i<n;i++)
        {
        cin>>a[i];
        if(i==0)
        b[stp] = a[i];

        else if(i%2 == 1)
            {
            stp += i;
            b[stp] = a[i];
            }
        else if(i%2 == 0)
            {
            stp -= i;
            b[stp] = a[i];
            }

        }
    }
for(usi i=0;i<n;i++)
    cout<<b[i];
return 0;
}
