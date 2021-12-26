#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void f(int a[],int n,int oe)
{
    if(oe%2 == 1)
    {
        for(int i=1; i<=(n-2); i+=2)
        {
            if(a[i] > a[i+1] )
            {
                int temp = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
    else
    {
        for(int i=2; i<=(n-1); i+=2)
        {
            if(a[i] > a[i+1] )
            {
                int temp  = a[i];
                a[i] = a[i+1];
                a[i+1] = temp;
            }
        }
    }
}

bool sorted(int a[],int b[],int n)
{
    for(int i=1; i<=n; i++)
    {
        if(a[i] != b[i])
            return 0;
    }
    return 1;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        int a[n+1];
        int b[n+1];
        a[0] = -1;
        b[0] = -1;

        for(int i=1; i<=n; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }

        sort(b,b+n+1);
        int c=0;
        while(sorted(a,b,n) == 0)
        {
            f(a,n,c+1);
            c++;
            //for(int i=1; i<=n; i++)
             //   cout<<a[i]<<" ";
            //cout<<"\n";
        }
        cout<<c<<"\n";
        t--;
    }
    return 0;
}
