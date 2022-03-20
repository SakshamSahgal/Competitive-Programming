#include<iostream>
using namespace std;

void Heapify(int a[],int n,int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l <= n && a[l] > a[largest])
        largest = l;

    if(r <= n && a[r] > a[largest])
        largest = r;

    if(largest != i)
    {
        swap(a[i],a[largest]);
        Heapify(a,largest,i);
    }
}


void Build_Heap(int a[],int n)
{
    for(int i=n/2; i>=1; i--)
        Heapify(a,n,i);
}

void heap_sort(int a[],int n)
{
    for(int i=n; i>1; i--)
    {
        swap(a[i],a[1]);
        Heapify(a,i-1,1);
    }
}

void array_printer(int a[],int n)
{
    cout<<"\n";
    for(int i=1; i<=n; i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    //GO_FAST
    int a[] = {-1,20,10,30,5,50,40};
    int n = 6;
    Build_Heap(a,6);
    array_printer(a,n);
    heap_sort(a,n);
    array_printer(a,n);
    //worst acase - > nlogn
    return 0;
}

