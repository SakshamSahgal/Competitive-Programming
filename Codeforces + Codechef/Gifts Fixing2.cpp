#include<iostream>
using namespace std;
long long int adder(long long int c1 , long long int c2)
{
if (c1 == c2)
    {
    return c2;
    }
else if(c1>c2)
    {
    return c1;
    }
else
    {
    return c2;
    }

}
int main()
{
   ios_base::sync_with_stdio(false);
   cin.tie(NULL);
  cout.tie(NULL);
short int t,n;
cin>>t;
while(t--)
    {
    cin>>n;
    long long int a[n],b[n],mini1=0,mini2=0,counter=0;

     for(int i=0;i<n;i++)
        {
        cin>>a[i];
        }
    for(int i=0;i<n;i++)
        {
       cin>>b[i];
        }


    mini1 = a[0];
    for(int i=1;i<n;i++)
        {
        if(a[i] < mini1)
            {
            mini1 = a[i];
            }
        }


    mini2 = b[0];
    for(int i=1;i<n;i++)
        {
        if(b[i] < mini2)
            {
            mini2 = b[i];
            }
        }
    //cout<<"mini1 = "<<mini1<<" mini 2 "<<mini2<<"\n";
    for(int i=0;i<n;i++)
        {
        if(a[i]> mini1 && b[i] > mini2)
            {
            counter += adder((a[i] - mini1),(b[i] - mini2));
            //cout<<"counter = \t"<<counter<<"\n";
            }
        else if(a[i]> mini1)
            {
            counter += (a[i] - mini1);
            //cout<<"counter = \t"<<counter<<"\n";
            }
        else if(b[i]> mini2)
            {
            counter += (b[i] - mini2);
            //cout<<"counter = \t"<<counter<<"\n";
            }
        }
        cout<<counter<<"\n";
    }

return 0;
}
