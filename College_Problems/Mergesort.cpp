#include<iostream>
using namespace std;

void merge_it(int a[],int l,int m,int r)
{
    //l , m
    //m+1 r
    int i=l;
    int j=m+1;
    int cur = 0;
    int *temp = new int[r-l+1];

    while(i <= m && j <= r)
    {
        if(a[i] < a[j])
            temp[cur++] = a[i++];
        else
            temp[cur++] = a[j++];
    }

    while(i<=m)
        temp[cur++] = a[i++];
    while(j<=r)
        temp[cur++] = a[j++];

    cur=0;
    for(int i=l;i<=r;i++)
        a[i] = temp[cur++];
}

void merge_sort(int a[],int n,int l,int r)
{
    if(l<r)
    {
        int m = (l+r)/2;
        merge_sort(a,n,l,m);
        merge_sort(a,n,m+1,r);
        cout<<"l = "<<l<<" r = "<<r<<"\n";
        merge_it(a,l,m,r);
    }
}

void array_printer(int a[],int n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
}

int main()
{
    //GO_FAST
    int a[] = {6,5,4,3,2,1};
    merge_sort(a,6,0,5);
    array_printer(a,6);
    return 0;
}

