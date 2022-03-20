#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number n\n";
    cin>>n;

    int low = 1;
    int high = n;
    int x = 1;

    while(low <= high)
    {
        int mid = (low+high)/2;
        if( mid*mid*mid <= n)
        {
            x = mid;
            low = mid+1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout<<"x = "<<x<<"\n";
    cout<<"its complexity is - log(n) \n";
    return 0;
}
