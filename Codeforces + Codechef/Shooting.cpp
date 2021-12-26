#include<iostream>
#include<algorithm>
#define si short int
using namespace std;
int main()
{
si n;
cin>>n;
si a[n];
si b[n];
si flag[n];
for(si i=0;i<n;i++)
    {
    cin>>a[i];
    b[i] = a[i];
    flag[i] = 0;
    }

sort(a,a+n,greater<int>());

cout<<"\na = ";
for(si i=0;i<n;i++)
cout<<" "<<a[i]<<" ";

cout<<"\nb = ";
for(si i=0;i<n;i++)
cout<<" "<<b[i]<<" ";

for(si i=0;i<n;i++)
    {
        for(si j=0;j<n;j++)
        {
                if(a[i] == b[j] && flag[j] == 0)
                {
                   b[j] = (i+1);
                   flag[j] = 1;
                    for(si i=0;i<n;i++)
                        cout<<" "<<flag[i]<<" ";
                    cout<<"\n";
                }
        }
    }

cout<<"\n";
for(si i=0;i<n;i++)
    cout<<" "<<b[i]<<" ";



return 0;
}
