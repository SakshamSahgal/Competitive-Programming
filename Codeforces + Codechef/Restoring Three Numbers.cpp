#include<iostream>
using namespace std;
int main()
{
int s,index = 0,x1,x2,x3,x4,countit=0;

int arr[4];
int a2[3];
for(int i=0;i<4;i++)
    {
        cin>>arr[i];
    }
   s = arr[0];

for(int i=0;i<4;i++)
    {
    if(s<arr[i])
        {
        s = arr[i];
        index = i;
        }
    }
for(int i=0;i<4;i++)
    {
    if(i != index)
        {
        a2[countit] = arr[i];
        countit++;
        }
    }
/*
cout<<"\n";
for(int i=0;i<4;i++)
    {
        cout<<arr[i];
    }

cout<<"\n a2= ";
for(int i=0;i<3;i++)
    {
        cout<<a2[i]<<"\t";
    }
cout<<"\n"; */
x3 = s - a2[0];
x1 = a2[2] - x3;
x2 = a2[0] - x1;

cout<<x1<<" "<<x2<<" "<<x3<<" ";
return 0;
}
