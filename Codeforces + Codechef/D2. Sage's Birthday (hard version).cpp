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
    //GO_FAST
    lli n;
    cin>>n;
    lli a[n];
    for(int i=0;i<n;i++)
        cin>>a[i];
    lli b[n];
    sort(a,a+n);

    for(int i=n/2,j=0;i<n;i++,j+=2)
        b[j] = a[i];

    for(int i=0,j=1;i<n/2;i++,j+=2)
        b[j] = a[i];

    lli c=0;


   // for(int i=0;i<n;i++)
   //     cout<<a[i]<<" ";
   // cout<<"\n";

    for(int i=1;i<=n-2;i++)
        if(b[i] < b[i-1] && b[i] < b[i+1])
            c++;

    cout<<c<<"\n";

    for(int i=0;i<n;i++)
        cout<<b[i]<<" ";
    return 0;
}
