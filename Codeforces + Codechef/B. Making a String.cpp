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
    GO_FAST
    lli n;
    cin>>n;
    lli a[n];

    for(int i=0;i<n;i++)
        cin>>a[i];
    sort(a,a+n,greater<lli>());
    lli th = a[0];
    lli sum=0;

    for(int i=0;i<n;i++)
    {
        th = max(min(th,a[i]),(lli)0);
        //cout<<"th = "<<th<<"\n";
        sum += th;
        th--;
    }
    cout<<sum<<"\n";
    return 0;
}
