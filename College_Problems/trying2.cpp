#include<iostream>
using namespace std;

int *quicksort(int a[],int n)
{
    int p = a[0];
    int hc=0;
    int pc=0;
    int lc=0;
    int *high = new int[n];
    int *low = new int[n];

    for(int i=0;i<n;i++)
    {
        if(a[i] < p)
            low[lc++] = a[i];
        else if(a[i] > p)
            high[hc++] = a[i];
        else
            pc++;
    }

    if(lc > 1)
        low = quicksort(low,lc);
    if(hc > 1)
        high = quicksort(high,hc);

    int *temp = new int[lc+hc+pc];
    int cc=0;

    for(int i=0;i<lc;i++)
        temp[cc++] = low[i];

    for(int i=0;i<pc;i++)
        temp[cc++] = p;

    for(int i=0;i<hc;i++)
        temp[cc++] = high[i];

    return temp;
}

void printer(int a[],int n)
{
    cout<<"\n";
    for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
    cout<<"\n";
}

int main()
{
    //GO_FAST

    int b[] = {15,25,17,8,3,2,23,23,8};
    int *a = quicksort(b,9);
    printer(a,9);



    return 0;
}

