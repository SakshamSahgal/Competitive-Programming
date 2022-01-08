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

lli req(lli a,lli b,lli x)
{
    if( (x*a) >= b )
        return (x*a - b);
    else
        return 0;
}

bool is_possible(vector<lli> &a,vector<lli> &b,lli x,lli k)
{
    for(int i=0; i<a.size(); i++)
    {
        k -= req(a[i],b[i],x);
        if(k < 0 )
            return 0;
    }
    return 1;
}

int main()
{
    GO_FAST

    lli n,k;
    cin>>n>>k;
    vector<lli> a(n);
    vector<lli> b(n);
    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<n; i++)
        cin>>b[i];

    lli low = 0;
    lli high = 2*1e9;
    lli mid=0;
    lli ans=0;
    while(low<=high)
    {
        mid = (low+high)/2;
        //cout<<"Trying "<<mid<<" ";
        if(is_possible(a,b,mid,k))
        {
            //cout<<"Possible\n";
            ans = mid;
            low = mid + 1;
        }
        else
        {
            //cout<<"Not Possible\n";
            high = mid - 1;
        }
    }
    cout<<ans<<"\n";
    return 0;
}
