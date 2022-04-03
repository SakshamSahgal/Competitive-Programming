
#include<iostream>
using namespace std;

int *quick_sort(int a[][2],int n)
{
    int low[n][2];
    int high[n][2];
    int lc=0;
    int hc=0;
    int pc=0;
    int p = a[0][1];

    for(int i=0;i<n;i++)
    {
        if(a[i] == p)
            pc++;
        else if(a[i] < p)
            low[lc++] = a[i];
        else
            high[hc++] = a[i];
    }

    if(lc > 1)
        low = quick_sort(low,lc);
    if(hc > 1)
        high = quick_sort(high,hc);

    int *temp = new int[lc+pc+hc];

    int i=0;

    for(int j=0;j<lc;j++)
        temp[i++] = low[j];

    for(int j=0;j<pc;j++)
        temp[i++] = p;

    for(int j=0;j<hc;j++)
        temp[i++] = high[j];

    return temp;
}

int main()
{
    int n;
    cin>>n;
    int a[n][2];
    for(int i=0; i<n; i++)
        cin>>a[i][0]>>a[i][1];

    a = quick_sort(a,7);

    for(int i=0;i<7;i++)
        cout<<a[i]<<" ";


    return 0;
}

