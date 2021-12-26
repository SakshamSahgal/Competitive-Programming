#include<iostream>
using namespace std;
void bubble_Sorting(int a[],int n)
{
int temp;
bool checker = 1;
for(int i=1;i<n;i++)
    {
    checker = 0;
    for(int j=0;j<=(n-1-i);j++)
        {
        if(a[j]>a[j+1])
            {
            checker = 1;
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            }
        }
    if(checker == 0)
        break;
    }
}



int main()
{

int a[] {3,4,1,0,6,4};
bubble_Sorting(a,6);
cout<<"\n";
for(int i=0;i<6;i++)
    cout<<a[i]<<" ";
return 0;
}
