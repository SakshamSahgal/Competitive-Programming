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
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        lli a[n];
        lli w[k];
        vector<pair<lli,lli>> ans(k);
        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<k; i++)
            cin>>w[i];

        sort(w,w+k);
        sort(a,a+n);
        lli l=n-1;
        for(int i=0; i<k; i++,l--)
        {
            ans[i].second = a[l];
            a[l] = -1;
        }

        for(int i=0; i<k; i++)
        {
            if(w[i] - 1 > 0)
            {
                l -= (w[i]-2);
                ans[i].first = a[l];
                a[l]=-1;
                l--;
            }
            else
                ans[i].first = ans[i].second;
        }
        lli sum=0;
        for(auto i:ans)
        {
            //cout<<i.first<<" "<<i.second<<"\n";
            sum += (i.first + i.second);
        }

        cout<<sum<<"\n";

        t--;
    }
    return 0;
}
