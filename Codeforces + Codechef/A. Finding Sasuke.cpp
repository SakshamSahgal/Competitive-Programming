#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t--)
    {
    int index = 0;
    usi n;
    cin>>n;
    int a[n],b[n];
    for(usi i=0;i<n;i++)
        cin>>a[i];
    usi sumx=0,sumy=0;
    for(usi i=0;i<n/2;i++)
        sumx+=a[i];
    for(usi i=(n/2);i<n;i++)
        sumy+=a[i];
    //cout<<"\n"<<sumx<<" "<<sumy<<"\n";
    if(sumx == sumy)
        {
        for(usi i=0;i<n/2;i++)
            b[i] = 1;
        for(usi i=(n/2);i<n;i++)
            b[i] = -1;
        }
    else if(sumx > sumy)
        {
        for(usi i=0;i<n/2;i++)
            b[i] = 1;
        for(usi i=(n/2);i<n;i++)
            {
                if((sumx-sumy)%a[i] == 0)
                    {
                    b[i] = -1*((sumx-sumy)/a[i] + 1);
                    index = i;
                    break;
                    }
            }

            for(usi i=(n/2);i<n;i++)
                {
                if(i!=index)
                    b[i] = -1;
                }

        }
    else if(sumx < sumy)
        {
        for(usi i=0;i<n/2;i++)
            {
                if((sumy-sumx)%a[i] == 0)
                    {
                    b[i] = -1*((sumy-sumx)/a[i] + 1);
                    index = i;
                    break;
                    }
            }
        for(usi i=0;i<n/2;i++)
            {
                if(i!=index)
                    b[i] = -1;

            }

        for(usi i=(n/2);i<n;i++)
            b[i] = 1;

        }

    for(usi i=0;i<n;i++)
        cout<<b[i]<<" ";
        cout<<"\n";
    }
return 0;
}
