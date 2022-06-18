#include<iostream>
using namespace std;

//median sort
//finding kth biggest


int median_search(int *a,int x,int sz)
{
    int ec=0,hc=0,lc=0;
    int *e = new int [sz];
    int *l = new int [sz];
    int *h = new int [sz];

    for(int i=0;i<sz;i++)
    {
        if(a[i] == a[0])
            e[ec++] = a[i];
        else if(a[i] > a[0])
            h[hc++] = a[i];
        else
            l[lc++] = a[i];
    }

    if(x <= hc)
        median_search(h,x,hc);
    else if(x <= (hc+ec))
        return a[0];
    else
        median_search(l,x-hc-ec,lc);
}

int main()
{
    int a[] = {50,25,47,12,1,8,78,95,24,47,50};
    cout<<median_search(a,11-7+1,11);
    return 0;
}
