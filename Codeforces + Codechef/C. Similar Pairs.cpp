#include<iostream>
#include<algorithm>
#define usi unsigned short int
using namespace std;
void printer(usi a[],usi n)
{
cout<<"\n-----------------\n";
for(usi i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n-----------------\n";
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
    usi n,p=0;
    cin>>n;
    usi a[n];
    for(usi i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n);
    //printer(a,n);
    bool found = 0;
    for(usi i=0;i<(n-1);i++)
        {

        if(a[i]+1 == a[i+1] && a[i] != 0 && a[i+1] != 0)
            {
            a[i] = 0;
            a[i+1] = 0;
            p++;
           // cout<<"pair found = "<<i<<" "<<i+1<<"\n";
               i++;
            }
        else
            {
                found = 0;
                usi j=0;
                for(j=0;j<n;j++)
                    {
                    if(a[j]!= 0 && a[i] != 0 && i!=j)
                        {

                        if(a[i]%2 == a[j]%2 && a[i] != 0 && a[j] != 0 )
                            {
                            a[i] = 0;
                            a[j] = 0;
                            p++;
                            found = 1;
                           // cout<<"pair found = "<<i<<" "<<j<<"\n";
                            break;
                            }

                        }
                    }

                if(found == 0)
                    {
                    cout<<"NO\n";
                    goto x;
                    }

                if(j == i+1)
                    i++;
            }
       // printer(a,n);
        }

    //cout<<"p == "<<p<<"\n";

    if(p == (n/2))
        cout<<"YES\n";
    else
         cout<<"NO\n";
    x:
    p=p;
    }





return 0;
}
