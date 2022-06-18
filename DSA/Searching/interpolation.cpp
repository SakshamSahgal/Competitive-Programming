#include<iostream>
using namespace std;

int a[] = {5,10,15,20,25,30,35,40,45};
bool interpolation_search(int l,int h,int x)
{
    if(h >= l)
    {
        int mid = l + (((h-l)/(a[h] - a[l]))*(x - a[l]));
        if(a[mid] == x)
            return 1;
        else if(x > a[mid])
            interpolation_search(mid+1,h,x);
        else
            interpolation_search(l,mid-1,x);
    }
    else
        return 0;

}


int main()
{
    cout<<interpolation_search(0,8,22);
    /*
    Best Case : Omega(1)
    Average Case : Theta(logN)
    Worst Case : O(N)

    We should Apply interpolation search only when we know that the data is
    uniformly distributed and does not have huge variations in values ,
    because in worst case it can go upto O(N) whereas in Binary search in worst
    case it can go upto O(logN)

    */
    return 0;
}
