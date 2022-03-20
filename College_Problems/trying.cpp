#include<iostream>

using namespace std;


void join(int a[],int l,int h)
{
    int m = (l+h)/2;
    int *temp = new int[h-l+1];

    int i=l;
    int j=m+1;
    int cc=0;
    while(i<=m && j<=h)
    {
        if(a[i] < a[j])
            temp[cc++] = a[i++];
        else
            temp[cc++] = a[j++];
    }

    while(i<=m)
        temp[cc++] = a[i++];

    while(j<=h)
        temp[cc++] = a[j++];

    cc=0;
    for(int i=l;i<=h;i++)
        a[i] = temp[cc++];
}

void printer(int a[],int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

void merge_sort(int a[],int l,int h)
{
    if(l < h)
    {
        int m = (l+h)/2;
        merge_sort(a,l,m);
        merge_sort(a,m+1,h);
        join(a,l,h);
    }
}

int main()
{
    //GO_FAST
    int a[] = {15,25,17,8,3,2,23,23,8};
    merge_sort(a,0,8);
    printer(a,9);
    return 0;
}

