#include <iostream>
using namespace std;

int binarySearch(int arr[], int l, int r, int x)
{
    while (l <= r)
    {
        int m = l + (r-l)/2;
        if (arr[m] == x)
            return m;

        if (arr[m] < x)
            l = m + 1;
        else
            r = m - 1;
    }
    return -1;
}


int main()
{
    int a[] = {10,20,30,40,50};
    int sizee = 5;
    int val;
    cout<<"Enter elements which you want to search: ";
    cin>>val;
    int ans = binarySearch(a, 0, sizee - 1,val);
    if(ans == -1)
        cout<<"Element was not found\n";
    else
        cout<<"Element was found at index: "<<ans;
    return 0;
}

