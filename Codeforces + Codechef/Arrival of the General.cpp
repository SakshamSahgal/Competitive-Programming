#include<iostream>>
using namespace std;

int Min_Index(int arr[],int n)
{
    int minimum = arr[0];
for(int i=0;i<n;i++)
    {
    if(minimum>arr[i])
        {
        minimum = arr[i];
        }
    }
for(int i=n-1;i>=0;i--)
    {
    if(arr[i] == minimum)
        {
        return i;
        break;
        }
    }
}

int Max_Index(int arr[],int n)
{
int maximum = arr[0];
for(int i=0;i<n;i++)
    {
    if(maximum<arr[i])
        {
        maximum = arr[i];
        }
    }
for(int i=0;i<n;i++)
    {
    if(arr[i] == maximum)
        {
        return i;
        break;
        }
    }
}
/*
void Printer(int arr[],int n)
{
for(int i=0;i<n;i++)
    {
      cout<<arr[i]<<"\t";
    }
cout<<"\n";
}
*/
int main()
{
int n,temp,countit=0;
cin>>n;
int arr[n];
for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }
//cout<<"\n"<<Min_Index(arr,n);
//cout<<"\n"<<Max_Index(arr,n)<<"\n";

for(int i = Max_Index(arr,n);i>=1;i--)
    {
    temp = arr[i-1];
    arr[i-1] = arr[i];
    arr[i] = temp;
    countit++;
   // Printer(arr,n);
    }
for(int i = Min_Index(arr,n);i<n-1;i++)
    {
        temp = arr[i+1];
        arr[i+1] = arr[i];
        arr[i] = temp;
        countit++;
       // Printer(arr,n);
    }
cout<<countit;
return 0;
}
