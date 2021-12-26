#include<iostream>
using namespace std;
void inputter(int *a[],int n)
{
for(int i=0;i<n;i++)
            {
            cin>>*a[i];
            }
}

int main()
{
int t;
cin>>t;
while(t--)
    {
        int n;
        cin>>n;
        int a[n];
        inputter(&a[],n);
        cout<<"----------------\n";
        for(int i=0;i<n;i++)
            {
            cout<<a[i];
            }
        cout<<"----------------\n";
    }
return 0;
}
