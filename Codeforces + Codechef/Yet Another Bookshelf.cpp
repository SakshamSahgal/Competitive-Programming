#include<iostream>
using namespace std;
int main()
{
int t,first_one_encountered_at = 0,counter=0,last_one_encountered_at =0;
cin>>t;
while(t--)
    {
    first_one_encountered_at = 0;
    counter = 0;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        {
        cin>>arr[i];
        }
        for(int i=0;i<n;i++)
        {
        if(arr[i] == 1)
            {
            first_one_encountered_at = i;
            break;
            }
        }
    for(int i=n-1;i>=0;i--)
        {
        if(arr[i] == 1)
            {
            last_one_encountered_at = i;
            break;
            }
        }
    for(int i=first_one_encountered_at+1 ;i>first_one_encountered_at && i<last_one_encountered_at;i++)
        {
            if(arr[i] == 0)
                {
                counter++;
                }
        }
    cout<<counter<<"\n";
    }
}
