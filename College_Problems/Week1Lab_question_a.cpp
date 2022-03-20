#include<iostream>

using namespace std;

void bubble_sort(int *a,int n)
{

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n-1-i;j++)
            {
                if(a[j] > a[j+1])
                    swap(a[j],a[j+1]);
            }
    }

}

void selection_Sort(int *a,int n)
{
    for(int i=0;i<n;i++)
    {
        int mini = INT_MAX;
        int index=i;
        for(int j=i;j<n;j++)
        {
            if(a[j] < mini)
            {
                mini = a[j];
                index = j;
            }
        }
        swap(a[i],a[index]);
    }
}

void insertion_sort(int *a,int n)
{
    for(int i=1;i<n;i++)
    {
        int key = a[i];
        int j=i-1;
        while( j >= 0 && a[j] > key)
        {
            a[j+1] = a[j];
            a[j] = key;
            j--;
        }

    }

}

void array_printer(int *a,int n)
{
    cout<<"\n----------------\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

void reset_array(int *a,int n)
{
    int b[] = {2,4,12,4,14,13,5};
    for(int i=0;i<n;i++)
        a[i] = b[i];
}



int main()
{
    //GO_FAST
    int *a;
    int n = 7;
    reset_array(a,n);
    cout<<"Before bubble sort - \n";
    array_printer(a,n);
    bubble_sort(a,n);
    cout<<"After Bubble Sort - \n";
    array_printer(a,n);
    reset_array(a,n);
    cout<<"Before selection sort - \n";
    array_printer(a,n);
    selection_Sort(a,n);
    cout<<"After Selection Sort - \n";
    array_printer(a,n);
    reset_array(a,n);
    cout<<"Before Insertion sort - \n";
    array_printer(a,n);
    insertion_sort(a,n);
    cout<<"After Insertion Sort - \n";
    array_printer(a,n);
    reset_array(a,n);
    return 0;
}

