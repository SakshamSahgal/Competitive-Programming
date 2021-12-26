#include<iostream>
using namespace std;
int main()
{
char arr[1000];
cin>>arr;
if(arr[0]>=97 && arr[0]<=122)
    {
    arr[0] = arr[0] - 32;
    cout<<arr;
    }
else
    {
    cout<<arr;
    }
return 0;
}
