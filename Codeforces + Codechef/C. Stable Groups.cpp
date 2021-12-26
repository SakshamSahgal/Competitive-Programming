#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<unordered_set>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


struct diff
{
    lli first;
    lli second;
    lli diff;
};


void Printer(diff d[],int s)
{
    cout<<"\n----------------------------\n";
    for(int i=0; i<s; i++)
        cout<<d[i].diff<<" "<<d[i].first<<" "<<d[i].second<<"\n";
    cout<<"\n----------------------------\n";
}

void array_printer(int a[],int n)
{
    cout<<"\n----------------------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------------------\n";
}

bool my_sort(diff d1,diff d2)
{
    return (d1.diff<d2.diff);
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    lli n,k,x;
    cin>>n>>k>>x;
    lli a[n];
    unordered_set<lli> y;
    lli maxx = INT_MIN;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>maxx)
            maxx = a[i];
        y.insert(a[i]);
    }

    //cout<<y.size()<<"\n";

    if( (maxx - y.size()) <= k )
        cout<<1<<"\n";
    else
    {

        diff d[n-1];
        sort(a,a+n);
       // array_printer(a,n);
        for(int i=0; i<(n-1); i++)
        {
            d[i].diff = a[i+1] - a[i];
            d[i].first = i;
            d[i].second = i+1;
        }
      // Printer(d,n-1);
        sort(d,d+n-1,my_sort);
      // Printer(d,n-1);
        lli g=1;
        for(int i=0;i<(n-1);i++)
            {
                if(d[i].diff > x)
                    {
                        //cout<<"comparing "<<((d[i].diff - 1)/x)<<" "<<k<<" "<<i<<"\n";
                        if(((d[i].diff - 1)/x) <= k)
                        {
                            k-=((d[i].diff - 1)/x);
                        }
                        else
                            g++;
                    }

            }
    cout<<g<<"\n";
    }

    return 0;
}
