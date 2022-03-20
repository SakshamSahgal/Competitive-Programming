#include<iostream>
using namespace std;


int *Quick_Sort(int *a,int sz)
{
    int *low = new int[sz];
    int *high = new int[sz];
    int lc=0,hc=0,pc=0;
    int pivot = a[0];

    for(int i=0;i<sz;i++)
    {
        if(a[i] < pivot)
            low[lc++] = a[i];
        else if( a[i] > pivot)
            high[hc++] = a[i];
        else
            pc++;
    }

    if(lc > 1)
        low = Quick_Sort(low,lc);
    if(hc > 1)
        high = Quick_Sort(high,hc);

    int *temp = new int[lc+pc+hc];
    int j=0;
    for(int i=0;i<lc;i++)
        temp[j++] = low[i];
    for(int i=0;i<pc;i++)
        temp[j++] = pivot;
    for(int i=0;i<hc;i++)
        temp[j++] = high[i];

    return temp;

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
    int *a = new int[8];
    int n = 8;
    // 1 3 1 4 21 12 13 5

    for(int i=0;i<n;i++)
        cin>>a[i];

    a = Quick_Sort(a,n);
    array_printer(a,n);
    return 0;
}

