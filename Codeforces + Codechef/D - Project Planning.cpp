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

void array_printer(lli a[],lli n)
{
cout<<"\n----------------\n";
for(int i=0;i<n;i++)
    cout<<a[i]<<" ";
cout<<"\n----------------\n";
}

int main()
{
    GO_FAST
    lli n,k;
    cin>>n>>k;
    lli a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    lli sum=0;

    //sort(a,a+n);
  //  array_printer(a,n);

    while(1)
    {
        sort(a,a+n);

        if(a[n-k] > 0)
        {
            lli d = a[n-k];
            sum += d;
            for(int i=n-k; i<n; i++)
                a[i] -= d;
          //  array_printer(a,n);
        }
        else
            break;
    }

    cout<<sum<<"\n";

    return 0;
}
