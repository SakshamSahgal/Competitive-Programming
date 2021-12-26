#include<iostream>
using namespace std;
#define si short int
int main()
{
si n,m;
cin>>n>>m;
si a[n];
for(si i=0;i<n;i++)
    {
    cin>>a[i];
    }

//bubble sorting
short int temp;
bool flag = 1;
for(si i=0; (i<n && flag == 1) ;i++)
    {
        flag = 0;
        for(si j=0;j<(n-1-i);j++)
            {
            if(a[j]>a[j+1])
                {
                temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
                flag = 1;
                }
            }
    }
int sum = 0;
for(si i=0;i<m;i++)
    {
        if(a[i]<0)
            {
            sum += a[i];
            }
    }
cout<<abs(sum);
return 0;
}
