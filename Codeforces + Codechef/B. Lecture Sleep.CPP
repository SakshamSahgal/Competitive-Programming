#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;



struct lecture
{
    int theorems;
    bool sleep;
    int profit;
};


void struct_printer(struct lecture x[],int n)
{

    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<x[i].theorems<<" ";
    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<x[i].sleep<<" ";
    cout<<"\n";
    for(int i=0; i<n; i++)
        cout<<x[i].profit<<" ";
    cout<<"\n";
    cout<<"\n----------------\n";
}

int main()
{
    //ios_base::sync_with_stdio(false);
    //cin.tie(NULL);
    //cout.tie(NULL);
    int n,k;
    cin>>n>>k;
    lecture a[n];
    for(int i=0; i<n; i++)
        cin>>a[i].theorems;

    lli profit=0;
    lli sum=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i].sleep;
        if(a[i].sleep == 0)
            profit+=a[i].theorems;
        else
            sum+=a[i].theorems;

        a[i].profit = profit;
    }

    //struct_printer(a,n);

    int l,u;
    int maxx = INT_MIN;
    for(int i=0; i<=(n-k); i++)
    {
        //cout<<"index = "<<zeros[i]<<"\n";
        l = i;
        u = i+k-1;
            if(l!=0)
            {
                //cout<<"->"<<(a[u].profit - a[l-1].profit)<<"\n";
                if( (a[u].profit - a[l-1].profit) > maxx )
                    maxx = (a[u].profit - a[l-1].profit);
            }
            else
            {
                //cout<<"->"<<(a[u].profit)<<"\n";
                if( a[u].profit > maxx )
                    maxx = a[u].profit;
            }
    }

    if(maxx != INT_MIN)
    cout<<sum+maxx<<"\n";
    else
    cout<<sum<<"\n";
    return 0;
}
