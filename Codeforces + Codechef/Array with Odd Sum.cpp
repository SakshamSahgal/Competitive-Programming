#include<iostream>
using namespace std;

int main()
{
int n,all_even=0,all_odd=0,evencount=0,oddcount=0,t;

cin>>t;

while(t--)
{
    all_even = 0;
    all_odd = 0;
    evencount = 0;
    oddcount = 0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
    {
    cin>>arr[i];
    }

for(int i=0;i<n;i++)
    {
    if(arr[i]%2 == 0)
        {
        evencount+=1;
        }
    else
        {
        oddcount+=1;
        }
    }
if(evencount == n)
    {
    all_even = 1;
    }
if(oddcount == n)
    {
    all_odd = 1;
    }

if(all_even == 1)
    {
    cout<<"NO\n";
    goto a;
    }
if(all_odd == 1)
    {
    if(n %2 != 0)
        {
        cout<<"YES\n";
        goto a;
        }
    else
        {
        cout<<"NO\n";
        goto a;
        }
    }
if(all_even != 1 && all_odd != 1)
    {
    cout<<"YES\n";
    }
a:;
}
return 0;
}
