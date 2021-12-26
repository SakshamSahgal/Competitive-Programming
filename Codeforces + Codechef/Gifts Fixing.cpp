#include<iostream>
using namespace std;

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
    long int a[n],b[n],mini1=0,mini2=0,counter=1,d = 0;

    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        }
    for(int i=0;i<n;i++)
        {
       cin>>b[i];
        }
    cout<<"\n------------------------------------------------------\n";
    for(int i=0;i<n;i++)
        {
        cout<<a[i]<<" ";
        }
    cout<<"\n";
    for(int i=0;i<n;i++)
        {
        cout<<b[i]<<" ";
        }
    cout<<"\n------------------------------------------------------\n";
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
    cout<<"mini 1 = "<<mini1<<" "<<"mini2  = "<<mini2<<"\n";
        // searching
    for(int i=0;d == 0;i++)
        {
        d = 1;
        if( (a[i] > mini1) && (b[i]> mini2) )
            {

            a[i]--;
            b[i]--;
            counter++;
            if(i == (n-1))
                {
                i=-1;
                }
            }
        else if( (a[i] > mini1) )
            {

            a[i]--;
            counter++;
            if(i == n-1)
                {
                i=-1;
                }
            }
        else if( (b[i] > mini2) )
            {

            b[i]--;
            counter++;
            if(i == n-1)
                {
                i=-1;
                }
            }
                for(int i=0;i<n;i++)
                    {
                    if(a[i] != mini1 || b[i] != mini2)
                        {
                            d = 0;
                            break;
                        }
                    }
            cout<<"\n debugging "<<(i+1)<<"\n";
            cout<<"\n------------------------------------------------------\n";
            for(int i=0;i<n;i++)
                {
                cout<<a[i]<<" ";
                }
            cout<<"\n";
            for(int i=0;i<n;i++)
            {
            cout<<b[i]<<" ";
            }
            cout<<"\n------------------------------------------------------\n";
            }

    cout<<counter-1<<"\n";
    }



return 0;
}
