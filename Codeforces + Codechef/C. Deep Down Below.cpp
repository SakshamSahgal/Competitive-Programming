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



void pp(vector<pair<lli,lli>> x)
{
    for(int i=0; i<x.size(); i++)
        cout<<x[i].first<<" "<<x[i].second<<"\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        vector<pair<lli,lli>> ba;
        lli n;
        cin>>n;
        for(int i=1; i<=n; i++)
        {
            lli maxx = INT_MIN;

            int pbm=0;
            lli k;
            cin>>k;
            lli x = INT_MIN;
            for(lli j=0; j<k; j++)
            {
                lli a;
                cin>>a;
                x = max(a - j + 1,x);
            }
            ba.push_back({x,k});
        }

        sort(ba.begin(),ba.end());
       // pp(ba);
        lli maxx = INT_MIN;
        lli s = 0;
        for(int i=0; i<ba.size(); i++)
        {
            maxx = max(ba[i].first - s,maxx);
            s += ba[i].second;
        }
        cout<<maxx<<"\n";

        t--;
    }
    return 0;
}
