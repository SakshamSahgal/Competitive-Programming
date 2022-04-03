#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<queue>
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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    lli ct=1;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        sort(a,a+n);
        lli b[n];
        lli dp[n];
        queue<lli> ava;
        set<pair<lli,lli>> x;
        cout<<"Case #"<<(ct++)<<": ";
        for(lli i=0; i<n; i++)
        {
            dp[i] = -1;
            b[i] = i + 1 - a[i];
            ava.push(i);
        }

       // array_printer(b,n);
        map<lli,lli> ft;
        for(int i=0; i<n-1; i++)
        {
            x.insert({b[i+1],i+1});
            auto ptr = x.begin();
            pair<lli,lli> h = *ptr;
            //cout<<"front = "<<h.first<<"\n";
            while(x.size() != 0 && ava.size() != 0 && ava.front() < h.first && ava.front() <= i)
            {
                //cout<<"From "<<ava.front()<<" to = "<<(h.second)<<"\n";
                ft[ava.front()] = ptr->second;
                ava.pop();
            }
            x.erase(x.begin());
        }

        for(auto i:ft)
            dp[i.first] = i.second;

       // array_printer(dp,n);
        lli ans = -inf;
        for(int i=0; i<n; i++)
        {
            lli len = 1;
            if(dp[i] == -1)
                len = n - i;
            else
                len = dp[i] - i;

            len = max(len,(lli)1);
            //cout<<len<<"\n";
            ans = max(ans,len);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
