#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<iomanip>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;


void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

int main()
{
    GO_FAST

    lli n;
    cin>>n;
    lli a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    sort(a,a+n);
    array_printer(a,n);

    lli c=1;

    while( powl(c,n-1) <= pow(10,10))
    {

    }



    cout<<ans<<"\n";
    return 0;
}
