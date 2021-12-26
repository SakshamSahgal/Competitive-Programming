#include<iostream>
#define usi unsigned short int
using namespace std;
int main()
{
usi k,n;
cin>>n>>k;
usi a[n];
for(usi i=0;i<n;i++)
    cin>>a[i];
bool checker = 0;
usi temp;
for(usi i=0;i<n;i++)
    {
    checker = 1;
    for(usi j=0;j<n-1-i;j++)
        {
        if(a[j]<a[j+1])
            {
            temp = a[j];
            a[j] = a[j+1];
            a[j+1] = temp;
            checker = 0;
            }
        }
        if(checker == 1)
            break;
    }
cout<<a[k-1];
return 0;
}
