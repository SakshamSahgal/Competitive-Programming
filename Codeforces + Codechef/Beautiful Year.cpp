#include<iostream>
using namespace std;

int distinct(int n)
{
int a[4];
int counter = 0;
    while(n>0)
        {
         a[counter] = n%10;
            n /=10;
            counter++;
        }
for(int i=0;i<4;i++)
    {
    for(int j=i+1;j<4;j++)
        {
        if(a[i] == a[j])
            {
            return -1;
            }
        }
    }
return 1;
}

int main()
{
int n;
cin>>n;
for(n = n+1;distinct(n) != 1;n++)
    {
    }
cout<<n;
return 0;
}
