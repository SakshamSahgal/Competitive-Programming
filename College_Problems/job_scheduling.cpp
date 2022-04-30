#include<bits/stdc++.h>
using namespace std;


struct my_pair
{
int first;
int sec;
};



void merge_it(int l,int r,my_pair a[])
{
    int mid = (l+r)/2;
    my_pair *temp = new my_pair[r-l+1];
    int c=0;
    int i=l;
    int j = mid+1;
    while(i<=mid && j<=r)
    {
        if(a[i].sec < a[j].sec)
            temp[c++] = a[i++];
        else
            temp[c++] = a[j++];
    }

    while(i<=mid)
        temp[c++] = a[i++];
    while(j<=r)
        temp[c++] = a[j++];

    c=0;
    for(int i=l;i<=r;i++)
        a[i] = temp[c++];
}


void merge_sort(my_pair a[],int l,int r)
{
    if(l < r)
    {
        int mid = (l+r)/2;
        merge_sort(a,l,mid);
        merge_sort(a,mid+1,r);
        merge_it(l,r,a);
    }
}


void printer(my_pair a[],int n)
{
    for(int i=0;i<n;i++)
        cout<<" { "<<a[i].first<<" "<<a[i].sec<<" } ";
}
int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    my_pair a[5];

    a[0].first = 1;
    a[0].sec = 4;

    a[1].first = 0;
    a[1].sec = 2;

    a[2].first = 1;
    a[2].sec = 3;

    a[3].first = 2;
    a[3].sec = 5;

    a[4].first = 3;
    a[4].sec = 4;

    printer(a,5);
    merge_sort(a,0,4);
    cout<<"\n";
    printer(a,5);
    int last = 0;
    int c=0;
    for(int i=0;i<5;i++)
    {
        if(a[i].first >= last)
        {
            c++;
            last = a[i].sec;
        }

    }
    cout<<"\n"<<c<<"\n";
    return 0;
}
