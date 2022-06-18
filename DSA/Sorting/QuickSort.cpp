#include<iostream>
using namespace std;

int *Quick_Sort(int *a,int c)
{
    if(c == 1)
        return a;
    else
    {
        int *low = new int[c];
        int *High = new int[c];

        int lc=0,hc=0,pc=0;
        int p = a[0];
        for(int i=0; i<c; i++)
        {
            if(a[i] < p)
                low[lc++] = a[i];
            else if(a[i] > p)
                High[hc++] = a[i];
            else
                pc++;
        }

        if(lc >= 1)
            low = Quick_Sort(low,lc);
        if(hc >= 1)
            High = Quick_Sort(High,hc);


        int *temp = new int[lc+pc+hc];
        int i=0;
        for(int j=0;j<lc;j++)
          temp[i++] = low[j];
        for(int j=0;j<pc;j++)
            temp[i++] = p;
        for(int j=0;j<hc;j++)
            temp[i++] = High[j];
        return temp;
    }
}
    int main()
    {
        //GO_FAST
        int *a = new int[8];
        for(int i=0;i<8;i++)
            a[i] = 10-i;

        a = Quick_Sort(a,8);
        for(int i=0;i<8;i++)
        cout<<a[i]<<" ";
        return 0;
    }
