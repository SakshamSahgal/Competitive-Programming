#include<iostream>
using namespace std;
void swap(int *a,int *b)
{
int temp = *a;
*a = *b;
*b = temp;
}

void permute(int a[],int l,int r,int n)
{
if(l==r)
    {
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";

        cout<<"\n";
    }
else
    {
    for(int i=l;i<=r;i++)
        {
        swap(&a[l],&a[i]);
        permute(a,l+1,r,n);
        swap(&a[l],&a[i]);
        }
    }
}

int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    cin>>a[i];
cout<<"\n";
permute(a,0,(n-1),n);
return 0;
}

