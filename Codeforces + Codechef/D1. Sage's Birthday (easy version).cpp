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

int main()
{
    lli n;
    cin>>n;
    lli a[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    lli k;
    sort(a,a+n);
    lli b[n];
    if(n%2 == 1)
    {
        k = n/2;

        for(int i=1,j=0; j<k; j++,i+=2)
            b[i] = a[j];

        for(int i=n-1,j=n-1,l=0; l<=k; j--,i-=2,l++)
            b[i] = a[j];

        cout<<k<<"\n";
        for(auto i:b)
            cout<<i<<" ";
    }
    else
    {
        k = n/2 - 1;

        for(int i=1,j=0; j<k; j++,i+=2)
             b[i] = a[j];

        for(int i=n-2,j=n-1,l=0;l<n/2;j--,i-=2,l++)
                 b[i] = a[j];

        b[n-1] = a[k];

        cout<<k<<"\n";
        for(auto i:b)
            cout<<i<<" ";

    }


    cout<<"\n";
    return 0;
}
