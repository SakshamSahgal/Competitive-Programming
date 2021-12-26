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
    vector<lli> a(n);
    lli sum=0;
    for(lli i=0; i<n; i++)
    {
        cin>>a[i];
        sum+=a[i];
    }
    //cout<<"sum = "<<sum<<"\n";
    sort(a.begin(),a.end());
    lli m;
    cin>>m;

    for(int i=0; i<m; i++)
    {
        lli x,y;
        cin>>x>>y;
        auto aage = lower_bound(a.begin(),a.end(),x);
        lli coins;
        if(aage == a.end())
        {
            aage--;
            coins = ( max((lli)0,(lli)(x-(*aage))) +  max((lli)0,(lli)(y - (sum - (*aage)))));
        }
        else if(aage == a.begin())
            coins = ( max((lli)0,(lli)(x-(*aage))) +  max((lli)0,(lli)(y - (sum - (*aage)))));
        else
        {
            lli c1 = ( max((lli)0,(lli)(x-(*aage))) +  max((lli)0,(lli)(y - (sum - (*aage)))));
            aage--;
            lli c2 = ( max((lli)0,(lli)(x-(*aage))) +  max((lli)0,(lli)(y - (sum - (*aage)))));
            coins = min(c1,c2);
        }
        cout<<coins<<"\n";
        /*
        lli coins = INT_MAX;
        for(int j=0;j<n;j++)
        {
            coins = min( coins , ( max((lli)0,(lli)(x-a[j])) + max((lli)0,(lli)(y - (sum - a[j])))) );
            cout<<"coins to attack = "<< max((lli)0,(lli)(x-a[j]))<<" coins to attack = "<<max((lli)0,(lli)(y - (sum - a[j])))<<"\n";
            cout<<"coins for "<<a[j]<<" = "<<( max((lli)0,(lli)(x-a[j])) + max((lli)0,(lli)(y - (sum - a[j]))))<<"\n";
        }

        cout<<"ans = "<<coins<<"\n"; */


    }
    return 0;
}
