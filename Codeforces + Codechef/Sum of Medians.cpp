#include<iostream>
#define usi unsigned short int
#define ulli unsigned long long int
using namespace std;


ulli func(usi n,usi k,usi x,ulli a[],ulli sum,usi i,usi l)
    {
    if(i==(k+1))
        return sum;
    else
        {
        i++;
        l-=(x+1);
        sum+=a[l];
        func(n,k,x,a,sum,i,l);
        }

    }
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    usi n,k;
    cin>>n>>k;
    ulli a[n*k];
    for(usi i=0;i<n*k;i++)
        cin>>a[i];
    ulli sum=0;
    usi x = n/2;

    cout<<func(n,k,x,a,sum,1,(n*k))<<"\n";
    }
return 0;
}
