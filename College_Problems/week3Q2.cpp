#include<iostream>
using namespace std;

int main()
{
    //int a[] = {1,1,3,3,4,5,5,7,7,8,8};
    int a[] = {1,1,3,3,4,4,5,5,7,7,8};
    int n = sizeof(a)/sizeof(a[0]);
    int low = 0;
    int high = (n-1)/2;
    int ans = a[n-1];

    while(low <= high)
    {
        int mid = (low+high)/2;
        //cout<<"trying mid = "<<mid<<"\n";
        int check = (mid*2);
        if( check+1 < n && a[check] != a[check + 1])
        {
            ans = a[check];
            high = mid-1;
            break;
        }
        else
            low = mid+1;
    }

    cout<<"ans = "<<ans<<"\n";
    cout<<"its complexity is - log(n) \n";
    return 0;
}

