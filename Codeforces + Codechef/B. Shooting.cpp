#include<iostream>
using namespace std;
#define si short int
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
si n;
int sum=0;
cin>>n;
si a[n];
si b[n];
for(si i=0;i<n;i++)
    cin>>a[i];

si index = 0;
si maximum;

for(si u=0;u<n;u++)
    {
        maximum = a[index];
        for(si i=0;i<n;i++)
            {
                if(a[i]>maximum && a[i] != -1)
                {
                maximum = a[i];
                index = i;
                }
            }
                a[index] = -1;
                sum += maximum*u + 1;
                b[u] = index;

    }
cout<<sum<<"\n";
for(si i=0;i<n;i++)
    cout<<(b[i] + 1)<<" ";
return 0;
}
