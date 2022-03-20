#include<iostream>
using namespace std;



int main()
{
    //GO_FAST
    int a[] = {2,5,5,5,6,6,8,9,9,9};
    int n = 10;
    int low = 0;
    int high = n-1;
    int key = 5;
    int first_occ = -1;

    while(low <= high)
    {
        int mid = (low+high)/2;
        if(a[mid] == key)
        {
            first_occ = mid;
            high = mid-1;
        }
        else if(a[mid] < key)
            low = mid+1;
        else
            high = mid-1;
    }

    if(first_occ == -1)
        cout<<"Not found\n";
    else
    {
        low = 0;
        high = n-1;
        int last_occ = -1;
        while(low <= high)
        {
            int mid = (low+high)/2;
            if(a[mid] == key)
            {
                last_occ = mid;
                low = mid + 1;
            }
            else if(a[mid] < key)
                low = mid+1;
            else
                high = mid-1;
        }

        cout<<"first occ = "<<first_occ<<" last occ = "<<last_occ<<"\n";
    }



    return 0;
}

