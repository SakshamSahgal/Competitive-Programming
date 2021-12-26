#include<iostream>
#include<algorithm>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
usi nod(int n)
{
usi d=0;
while(n!=0)
    {
    n/=10;
    d++;
    }
return d;
}

int no(usi NOD,usi digit)
{
int nu = 0;
for(usi i=0;i<NOD;i++)
    {
    //cout<<digit*pow(10,i)<<"-";
    nu += digit*pow(10,i);
    }

return no;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
int n;
cin>>n;
usi temp = nod(n);
for(usi i=2;i<=temp;i++)
    {
        for(usi j=1;j<=9;j++)
            {
            cout<<nu(temp,j)<<" ";
            }

    }


return 0;
}
