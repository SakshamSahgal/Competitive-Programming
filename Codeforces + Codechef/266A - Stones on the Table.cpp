#include<iostream>
using namespace std;
int main()
{
int n,count = 0;
cin>>n;
char color[n];
for(int i=0;i<n;i++)
    {
    cin>>color[i];
    }
for(int i=0;i<n-1;i++)
    {
    if(color[i] == color[i+1])
        {
        count++;
        }
    }
cout<<count;
return 0;
}
