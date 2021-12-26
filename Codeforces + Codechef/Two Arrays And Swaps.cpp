#include<iostream>
using namespace std;

int n,k,t,countit = 0,temp;
int min_of_a=0;
int max_of_b=0;

int Maximumfinder(int arr[])
{
int Maximum = arr[0];
for(int i=0;i<n-1;i++)
    {
    if(Maximum<arr[i+1])
        {
        Maximum = arr[i+1];
        }
    }
return Maximum;
}
int Minfinder(int arr[])
{
int minimum = arr[0];
for(int i=0;i<n-1;i++)
    {
    if(minimum>arr[i+1])
        {
        minimum = arr[i+1];
        }
    }
return minimum;
}

int IndexReturner(int arr[],int element)
{
for(int i=0;i<n;i++)
    {
    if(arr[i] == element)
        {
        return i;
        break;
        }
    }
}

int Sumcalculator(int arr[])
{
int sum = 0;
for(int i=0;i<n;i++)
    {
    sum += arr[i];
    }
return sum;
}


/*void Array_Printer(int arr[])
{
for(int i=0;i<n;i++)
    {
    cout<<arr[i]<<"\t";
    }
    cout<<"\n";
}
*/
int main()
{
cin>>t;
while(t--)
    {
    cin>>n>>k;
    int a[n],b[n];
    for(int i=0;i<n;i++)
        {
        cin>>a[i];
        }
     for(int i=0;i<n;i++)
        {
        cin>>b[i];
        }
        while(countit<k)
            {
            min_of_a = Minfinder(a);
            max_of_b = Maximumfinder(b);
            if(min_of_a<max_of_b)
                {
                temp = a[IndexReturner(a,min_of_a)];
                a[IndexReturner(a,min_of_a)] = b[IndexReturner(b,max_of_b)];
                b[IndexReturner(b,max_of_b)] = temp;
                }
            countit++;
            }
            cout<<Sumcalculator(a)<<"\n";
            countit = 0;
    }

return 0;
}
