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


lli counter(vector <lli> &v,lli ll,lli ul)
{
    lli ans=0;
    for(auto i:v)
    {
        if( i >= ll && i <= ul)
            ans += 1;
    }
    return ans;
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

int main()
{
    //GO_FAST

    lli n;
    cin>>n;
    vector<lli> v(n);
    for(int i=0; i<n; i++)
        cin>>v[i];

    sort(v.begin(),v.end());
    //vector_printer(v);
    lli t;
    cin>>t;

    lli ll=1;
    lli uu=ll+t;
    lli ans = 0;

    do
    {
        ans = max(ans,counter(v,ll,uu));
        //cout<<"at "<<ll<<" to "<<uu<<" ans = "<<counter(v,ll,uu)<<"\n";
        ll++;
        uu++;
    }
    while(uu <= v[v.size()-1]);
    cout<<ans<<"\n";
    return 0;
}
