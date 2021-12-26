#include<iostream>
#include<algorithm>
using namespace std;
void printer(int arr[],int n)
{
for(int i=0;i<n;i++)
        {
        cout<<arr[i]<<" ";
        }
}
int main()
{

int t;
cin>>t;
while(t--)
    {
    int n;
    int countit = 0;
    cin>>n;
    int arr[n];
    int newer[n*n];
    for(int i=0;i<n;i++)
        {
        cin>>arr[i];
        }

    //printer(arr,n);
    for(int i=0;i<n*n;i++)
        {
        newer[i] = arr[countit];
        if(countit == (n-1))
            {
            countit = -1;
            }
            countit++;
        }
    int s = sizeof(arr)/sizeof(arr[0]);
    sort(arr,arr+s);
    //cout<<"\n";
    printer(newer,n*n);
    countit = 0;

    for(int i=0;i<n*n;i++)
        {

            if(newer[i] == arr[countit])
            {
                countit++;
                cout<<"\n index = "<<i;
            }

       for(int j=countit;arr[countit] == arr[countit-1];countit++)
                {

                }

        }
    cout<<countit<<"\n";
    }
return 0;
}
