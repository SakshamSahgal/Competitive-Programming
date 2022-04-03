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
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;



int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        set<pair<lli,lli>> y;
        for(int i=0;i<n;i++)
            cin>>a[i];
        map<lli,lli> ft;
        y.insert({a[n-1],n-1});
        for(int i=n-2;i>=0;i--)
        {
            y.insert({a[i],i});
            //cout<<"at i = "<<i<<"\n";
            auto ptr = (y.begin());
            while( (ptr->first) != a[i])
            {
                //cout<<"erasing"<<ptr->first<<"\n";

                ft[ptr->second] = i;
               // cout<<"from "<<i<<" to "<<ptr->second<<"\n";
                y.erase(y.begin());
                ptr = y.begin();
            }
        }

        lli dp[n] = {0};

        for(auto i:ft)
        {
            //cout<<i.first<<" "<<i.second<<"\n";
            dp[i.first] = i.second;
        }

        //array_printer(dp,n);
        lli ans[n];
        ans[0] = 0;
        for(int i=1;i<n;i++)
            ans[i] = ans[dp[i]] + 1;

        for(int i=0;i<n;i++)
            cout<<ans[i]<<" ";

        cout<<"\n";
        t--;
    }
    return 0;
}

