#include<iostream>
using namespace std;
int main()
{
int n,t,sum,countit =0;
cin>>t;
while(t--)
    {
    countit = 0;
    cin>>n;
    int arr[n];
    if((n/2)%2 == 0)
        {
            cout<<"YES\n";


            for(int i=0;i<n/2;i++)
            {
            arr[i] = 2*(i+1);
            }
                for(int i=n/2;i<n;i++)
                {
                        if(countit<(n/4))
                            {
                            arr[i] = arr[countit] - 1;
                            }
                        else if(countit>=(n/4))
                            {
                            arr[i] = arr[countit] + 1;
                            }
                        countit++;
                }
            for(int i=0;i<n;i++)
                {
                cout<<arr[i]<<" ";
                }
                cout<<"\n";
        }
            else
            {
            cout<<"NO\n";
            }
        }

return 0;
}
