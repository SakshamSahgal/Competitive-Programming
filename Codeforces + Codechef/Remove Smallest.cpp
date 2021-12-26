#include<iostream>
#include<cstdlib>
#include<algorithm>
using namespace std;
int main()
{
short int t,n,counter=0;
cin>>t;
while(t--)
    {
    counter = 0;
    cin>>n;
    short int a[n];

    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        }
    sort(a,a+n);
    for(int i=0;i<n-1;i++) //checking
        {
            if( (abs(a[i] - a[i+1])<=1))
                {
                    if(a[i]<=a[i+1])
                        {
                        a[i] = -1;
                        }
                    else
                        {
                        a[i+1] = -1;
                        }
                }
        }


    /*
    cout<<"\n";
        //printer
        for(int i=0;i<n;i++)
            {
            cout<<a[i]<<" ";
            }
    cout<<"\n"; */
        //counter
        for(int i=0;i<n;i++)
            {
                if(a[i] != -1)
                    {
                    counter++;
                    }
            }

        if(counter == 1)
            {
            cout<<"YES\n";
            }
        else
            {
            cout<<"NO\n";
            }
    }
return 0;
}
