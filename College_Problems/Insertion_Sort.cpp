#include<iostream>
using namespace std;

void insertion_sort(int a[],int n)
{
    for(int i=1; i<n; i++)
    {
        int key = a[i];
        int j = i-1;
        while(j>=0 && a[j] > key)
        {
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = key;
    }
}

void array_printer(int a[],int n)
{
    cout<<"\n-----------------------------\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n-----------------------------\n";
}

int main()
{
    //GO_FAST
    int a[] = {1,3,1,4,21,12,13,5};
    int n = 8;
    insertion_sort(a,n);
    array_printer(a,n);
    return 0;
}

