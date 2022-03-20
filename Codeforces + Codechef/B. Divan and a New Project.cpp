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

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<pair<lli,lli>> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i].first;
            a[i].second = i;
        }

        sort(a.begin(),a.end(),greater<pair<lli,lli>>());
        lli b[n];

        //pair_printer(a);
        lli ans = 0;
        for(int i=0,j=1; i<n; i++)
        {
            ans += (2*(a[i].first)*j);
            if(i%2 == 1)
            {
                b[a[i].second] = -j;
                j++;
            }
            else
                b[a[i].second] = j;

        }

        cout<<ans<<"\n0 ";

        for(int i=0; i<n; i++)
            cout<<b[i]<<" ";
        cout<<"\n";

        t--;
    }
    return 0;
}
