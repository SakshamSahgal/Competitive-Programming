#include<iostream>
using namespace std;
void insertion_Sort(int a[],int n)
    {
    int comparisons = 0;
    int temp;
    for(int i=1;i<n;i++)
        {
        temp = a[i];
        for(int j=i-1;j>=0 && temp<a[j];j--)
            {
            comparisons++;
            a[j+1] = a[j];
            a[j] = temp;
            }
        }
    cout<<"\n no of comparisons = "<<comparisons<<"\n";
    for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
    }

void inputter(int a[],int n)
{
    for(int i=0;i<n;i++)
        cin>>a[i];
}


int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
int n;
cin>>n;
int a[n];
inputter(a,n);
insertion_Sort(a,n);

cout<<"\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
return 0;
}
