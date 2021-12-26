#include<iostream>
using namespace std;
int main()
{
int k2,k3,k5,k6,i=0,sum=0,done=0;
cin>>k2>>k3>>k5>>k6;
for(i=0;done == 0;i++)
    {
    if(k2>0 && k5>0 && k6>0)
        {
        sum = sum + 256;
        --k2;
        --k5;
        --k6;
        }
    else if(k3>0 && k2>0)
        {
        sum = sum + 32;
        --k3;
        --k2;
        }
    else
        {
        done = 1;
        }
    //cout<<"hum andar hi h\n";
    }
cout<<sum;
return 0;
}
