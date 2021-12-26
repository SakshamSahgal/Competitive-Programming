#include<iostream>
using namespace std;

int insertion_sort_acc(short int a[],unsigned short int n)
{
int temp;
    for(int i=1;i<n;i++)
        {
        temp = a[i];
        for(int j=(i-1);j>=0 && temp<a[j];j--)
            {
                a[j+1] =a[j];
                a[j] = temp;
            }
        }

}


int insertion_sort_dec(short int a[],unsigned short int n)
{
int temp;
    for(int i=1;i<n;i++)
        {
        temp = a[i];
        for(int j=(i-1);j>=0 && temp>a[j];j--)
            {
                a[j+1] =a[j];
                a[j] = temp;
            }
        }

}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

unsigned short int t;
cin>>t;
while(t--)
    {
    unsigned short int n;
    cin>>n;
    short int a[n];
    for(unsigned short int i=0;i<n;i++)
        cin>>a[i];

    if(n==1)
        {
        if(a[0] == 0)
            {
            cout<<"NO\n";
            goto z;
            }
        else
            {
            cout<<"YES\n";
            cout<<a[0]<<"\n";
            goto z;
            }

        }

    insertion_sort_acc(a,n);
    int sum;
    for(int i=0;i<n;i++)
        {
           sum = 0;
        for(int j=0;j<=i;j++)
            sum+=a[j];

        if(sum == 0)
            goto y;
        }

        cout<<"YES\n";
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<"\n";
        goto z;

        y:
        insertion_sort_dec(a,n);

        for(int i=0;i<n;i++)
        {
           sum = 0;
        for(int j=0;j<=i;j++)
            sum+=a[j];

        if(sum == 0)
            {
            cout<<"No\n";
            goto z;
            }
        }

        cout<<"YES\n";
        for(int i=0;i<n;i++)
        cout<<a[i]<<" ";
        cout<<"\n";

    z:
    n=n;
    }
return 0;
}
