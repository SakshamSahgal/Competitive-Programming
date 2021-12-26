#include<iostream>
using namespace std;
int main()
{
int t,n,sum = 0,countit = 0,product=1;
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
            product *= arr[i];
            }

        if(product == 0)
            {
            for(int i=0;i<n;i++)
                {
                if(arr[i] == 0)
                    {
                    countit++;
                    arr[i] +=1;
                    }
                }
            }

        for(int i=0;i<n;i++)
            {
            sum += arr[i];
            }

        if(sum == 0)
            {
            countit++;
            }

        cout<<countit<<endl;
        countit = 0;
        sum = 0;
        product=1;
        }

return 0;
}

