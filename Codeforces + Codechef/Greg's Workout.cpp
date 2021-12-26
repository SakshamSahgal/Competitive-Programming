#include<iostream>
using namespace std;
int main()
{
int n;
cin>>n;
int arr[n],checkit[3]={0,0,0},j=0;
for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }
for(int i=0;i<n;i++)
    {
    if(j>=3)
        {
        j=0;
        }
    checkit[j] += arr[i];
    j++;
    }
if(checkit[0]>checkit[1] && checkit[0]>checkit[2])
    {
    cout<<"chest";
    }
else if(checkit[1]>checkit[0] && checkit[1]>checkit[2])
    {
    cout<<"biceps";
    }
else if(checkit[2]>checkit[0] && checkit[2]>checkit[1])
    {
    cout<<"back";
    }
return 0;
}

