#include<iostream>
using namespace std;

int binary_Search_it(int l,int h,int a[],int target)
{
    while(l<=h)
    {
        int m = (l+h)/2;
        if(a[m] == target)
            return m;
        else if(a[m] > target)
            h = m-1;
        else
            l = m+1;
    }
    return -1;
}

int main()
{
    //GO_FAST
    int n;
    cin>>n;
    int a[n];
    int piv = 0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(i != 0 && a[i-1] > a[i])
            piv = i-1;
    }
    int target;
    cout<<"Enter the element to search for \n";
    cin>>target;

    cout<<"Pivot = "<<piv<<"\n";

    int index_1 = binary_Search_it(0,piv,a,target);
    int index_2 = binary_Search_it(piv+1,n-1,a,target);

    if( index_1 != -1 || index_2 != -1)
        cout<<max(index_1,index_2)<<"\n";
    else
        cout<<"-1\n";


    return 0;
}

