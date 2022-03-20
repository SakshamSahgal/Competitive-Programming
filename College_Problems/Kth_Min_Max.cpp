#include<iostream>
using namespace std;


void Kth_Min(int a[],int n,int k)
{
    int p = a[0];
    int lc = 0;
    int pc = 0;
    int hc = 0;
    int *low = new int[n];
    int *high = new int[n];

    for(int i=0;i<n;i++)
    {
        if(a[i] < p)
            low[lc++] = a[i];
        else if(a[i] > p)
            high[hc++] = a[i];
        else
            pc++;
    }

    if(k <= lc)
        Kth_Min(low,lc,k);
    else if(k<=pc+lc)
    {
        cout<<"Kth smallest = "<<p<<"\n";
        return;
    }
    else
       Kth_Min(high,hc,k-lc-pc);
}

int main()
{
    //GO_FAST
    int a[] = {1,12,3,12,4,16,2,7};
    Kth_Min(a,8,3);
    return 0;
}

