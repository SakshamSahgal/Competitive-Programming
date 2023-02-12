#include<bits/stdc++.h>
using namespace std;
// int csas(int arr[], int n)
// {
//     int res=0;
//     for(int i=0;i<n;i++)
//     {
//         int curr_max=arr[i];
//         int curr_sum=arr[i];

//         for(int j=1;j<n;j++)
//         {
//             int index=(i+j)%n;
//             curr_sum+=arr[index];
//             curr_max=max(curr_sum,curr_max);

//         }
//         res=max(res,curr_max);//     }
//     return res;
// }
int csasopt(int arr[],int n)
{
   int res_max,res_min=arr[0];
   int maxending = -1e9 ,minending=arr[0];
    for(int i=0;i<n;i++)
    {
        maxending=max(maxending + arr[i], arr[i]);
        res_max=max(maxending,res_max);
        //minending=min(minending + arr[i],arr[i]);

        //res_min=min(minending,res_min);\
    }
    for(int i=0;i<n;i++)
    {
        minending=min(minending + arr[i],arr[i]);
        res_min=min(minending,res_min);
    }
    return (res_max-res_min);
}
int main()
{
    int n;
    cout<<"enter size of array-";
    cin>>n;
    int arr[n];
    cout<<"enter elements of array-";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<csasopt(arr,n);


}
