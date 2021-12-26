#include<iostream>
using namespace std;
//counting sort
int main()
{
int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++)
    cin>>a[i];

//maximum finder
int maximum = a[0];
for(int i=0;i<n;i++)
    {

    if(a[i]>maximum)
        {
        maximum = a[i];
        }
    }
int count_it[maximum + 1];

//filling 0 at every index

for(int i=0;i<=maximum;i++)
    count_it[i] = 0;


for(int i=0;i<n;i++)
    ++count_it[a[i]];


for(int i=1;i<=maximum;i++)
    count_it[i] = count_it[i] + count_it[i-1];


int b[n]; //sorted array

for(int i=(n-1);i>=0;i--)
    {
        b[--count_it[a[i]]] = a[i];
    }


    cout<<"\n";
for(int i=0;i<n;i++)
    cout<<b[i]<<" ";

return 0;
}
