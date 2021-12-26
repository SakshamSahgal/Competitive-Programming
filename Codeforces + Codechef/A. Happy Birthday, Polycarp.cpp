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

return nu;
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
usi t;
cin>>t;
while(t)
{
   int n;
    cin>>n;
if(n<=9)
    cout<<n<<"\n";
else
    {
        usi temp = nod(n);
        cout<<"nod = "<<temp<<"\n";
        usi c=9;
        for(usi i=2;i<=temp;i++)
        {
        for(usi j=1;j<=9;j++)
            {
            cout<<no(i,j)<<" ";
            if(no(i,j)>n)
                goto x;
            else
                c++;

            }

        }

    x:
    cout<<c<<"\n";
    }
t--;
}


return 0;
}
