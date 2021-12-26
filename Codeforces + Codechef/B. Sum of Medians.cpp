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
    usi n,k;
    cin>>n>>k;
    unsigned int a[n*k];
    for(usi i=0;i<n*k;i++)
        cin>>a[i];

    unsigned int ms1=0;
    unsigned int index;
    if(n%2==0)
        index = (n/2)-1;
    else
        index = (n/2);

    unsigned int b[k][n];
    unsigned int z = k+n-1;
    //cout<<"index = "<<index<<"\n";
    for(usi i=0;i<k;i++)
        {
          // cout<<"index = "<<index<<"\t";
           ms1 += a[index];
           index+=n;
            b[i][0] = a[i];


            for(usi j=z-n+1,l=1;j<z;j++,l++)
                {
                   //cout<<"j = "<<j<<"\t";
                    b[i][l] = a[j];
                }
            z+=(n-1);
           // cout<<"\n";
        }


        if(n%2==0)
        index = (n/2)-1;
        else
        index = (n/2);


     unsigned int ms2=0;

        for(unsigned int i=0;i<k;i++)
            {
                ms2 += b[i][index];
            }

       for(int i=0;i<k;i++)
            {
            for(int j=0;j<n;j++)
                        cout<<b[i][j]<<" ";
            cout<<"\n";
            }

        if(ms2>ms1)
        cout<<ms2<<"\n";
        else
        cout<<ms1<<"\n";

    }
return 0;
}
