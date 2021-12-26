#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>
#define usi unsigned short int
#define ui unsigned int
using namespace std;
void printer(int a[],int n)
{
//cout<<"\n---------\n";
for(int i=0;i<n;i++)
   printf("%d ",a[i]);
//cout<<"\n---------\n";
}
void flipper(int a[],int st,int ed)
{
int temp;
for(int i=st,c=ed;i<=((st+ed)/2);i++,c--)
    {
    temp = a[i];
    a[i] = a[c];
    a[c] = temp;
    }
}
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    scanf("%d",&a[i]);
for(int i=0;i<=(n-i-1);i++)
    flipper(a,i,(n-i-1));

printer(a,n);

return 0;
}
