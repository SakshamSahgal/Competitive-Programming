#include<iostream>
int minimum_finder(int arr[],int n)
    {
    int minu = arr[0];
    for(int i=0;i<n;i++)
        {
        if(arr[i]<minu)
            {
            minu = arr[i];
            }
        }
    return minu;
    }

int maximum_finder(int arr[],int n)
    {
    int maxi = arr[0];
    for(int i=0;i<n;i++)
        {
        if(arr[i]>maxi)
            {
            maxi = arr[i];
            }
        }
    return maxi;
    }


using namespace std;
int main()
{
int n,counter=0;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    {
    cin>>a[i];
        //cout<<"\n a["<<i<<"] = "<<a[i]<<" min till now = "<<minimum_finder(a,i)<<" maximum till now = "<<maximum_finder(a,i)<<"\n";
        if(a[i]<minimum_finder(a,i))
            {
                //cout<<"aaiya";
                counter++;
            }
        else if(a[i]>maximum_finder(a,i))
            {
                //cout<<"aaiya2";
                counter++;
            }
    }
cout<<counter;
return 0;
}
