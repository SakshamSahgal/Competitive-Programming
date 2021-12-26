#include<iostream>
#define usi unsigned short int
#define ui unsigned int
using namespace std;

int main()
{
ui n;
cin>>n;
//vector <pair<int,int>> a;
int temp;
unsigned long long int sum = 0;
ui nn=0,z=0;
for(usi i=0;i<n;i++)
    {
    cin>>temp;
    if(temp<0)
        {
        nn++;
        sum += (-1)*(temp+1);
        }
    else if(temp>0)
        {
        sum +=(temp-1);
        }
    else
        {
        z++;
        sum += 1;
        }
    }

if(nn%2 == 0)
    {
       cout<<sum<<"\n";
    }
else
    {
    if(z >=1)
        {
            cout<<sum<<"\n";
        }
    else
        {
            cout<<sum+2<<"\n";
        }
    }
return 0;
}
