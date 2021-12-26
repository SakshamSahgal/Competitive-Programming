#include<iostream>
using namespace std;
int main()
{
int n,checkit = 1,t;
cin>>t;
while(t--)
    {
    cin>>n;
int arr[n];
for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }
for(int i=0;i<n;i++)
    {
    for(int j=i+1;j<n;j++)
        {
        if(arr[i]<arr[j])
            {
               // cout<<" j--> "<<j<<"\n";
            for(int k=j+1;k<n;k++)
                {
                    if(arr[j]>arr[k])
                        {
                            //cout<<" k--> "<<k<<"\n";
                            cout<<"YES \n";
                            cout<<i+1<<" "<<j+1<<" "<<k+1<<"\n";
                            checkit = 0;
                            goto a;
                        }
                    else
                        {
                        goto b;
                        }
                }
            }

        }
        b:;
    }

a:
if(checkit == 1)
    {
    cout<<"NO\n";
    }
    checkit = 1;
    }
    return 0;
}
