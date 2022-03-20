#include<iostream>
using namespace std;


int binary_search_on(int l,int h,int arr[],int x)
{
    while(l<=h)
    {
        int mid = (l+h)/2;
        //cout<<"mid = "<<mid<<"\n";
        if(arr[mid] == 0)
            h = mid-1;
        else if(arr[mid] == x)
            return mid;
        else if(arr[mid] > x)
            h = mid-1;
        else
            l = mid+1;
    }
    return -1;
}

int main()
{
    //GO_FAST
    int a[] = {1,4,5,6,10,12,13,19,21,0,0,0,0,0,0,0,0,0,0,0,0};
    int x = 11;
    cout<<"Searching for = "<<x<<"\n";
    int n = sizeof(a)/sizeof(a[0]);
    int l = 0;
    int h = 0;
    int len=1;
    while(1)
    {
        //cout<<"len = "<<len<<" l = "<<l<<" h = "<<h<<"\n";
        if(len > n)
        {
            h = n-1;
            int index = binary_search_on(l,h,a,x);
            if(index != -1)
                cout<<"found on "<<index<<"\n";
            else
                cout<<"Not found\n";
            break;
        }
        else
        {
            int index = binary_search_on(l,h,a,x);
            if(index != -1)
            {
                cout<<" found on "<<index<<"\n";
                break;
            }
            else
            {
                //cout<<"not found trying again with "<<len*2<<"\n";
                len = len*2;
                h = l + len - 1;
            }

        }
    }

    return 0;
}

