#include<iostream>
using namespace std;

int b[100000] = {0};
int last = 1;

void insert_ele(int x)
{
    int i = last++;
    b[i] = x;
    while(i>1)
    {
        int par = b[i/2];
        if(par < b[i])
            swap(b[i/2],b[i]);
        i =  i/2;
    }
}

void delete_ele()
{
    b[1] = b[last-1];
    b[last-1] = 0;

    int i = 1;

    while(i < last)
    {
        int lc = b[2*i];
        int rc = b[2*i + 1];
        if(b[i] < max(lc,rc))
        {
            if(lc > rc)
            {
                swap(b[i],b[2*i]);
                i = 2*i;
            }
            else
            {
                swap(b[i],b[2*i + 1]);
                i = 2*i+1;
            }
        }
        else
            break;
    }

    last--;
}

void array_printer(int a[],int n)
{
cout<<"\n----------------\n";
for(int i=1;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
}


void Heapify(int a[],int n,int i)
{
    int largest = i;
    int l = 2*i;
    int r = 2*i+1;

    if(l <= n && a[l] > a[largest])
        largest = l;

    if(r <= n && a[r] > a[largest])
        largest = r;

    if(largest != i)
    {
        swap(a[i],a[largest]);
        Heapify(a,largest,i);
    }
}

int main()
{
    int a[] = {-1,15,10,20,30,40,5};

    for(int i=1;i<=6;i++)
    {
        insert_ele(a[i]);
        array_printer(b,last);
    }

    for(int i=1;i<=6;i++)
    {
        delete_ele();
        array_printer(b,last);
    }


    for(int i=1;i<=6;i++)
        cout<<a[i]<<" ";

    return 0;
}

