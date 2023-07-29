#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

vector<pair<lli,lli>> consecutive_freq(lli a[],lli n)
{
    vector<pair<lli,lli>> x;
    lli i=0;
    while(i < n)
    {
        lli c=1;
        lli j=i+1;

        while( j < n && a[j] == a[i])
        {
            j++;
            c++;
        }
        //cout<<" from = "<<i<<" to "<<j-1<<"\n";
        x.push_back({a[i],c});
        i = j;
    }
    return x;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0;i<n;i++)
            cin>>a[i];
        vector<pair<lli,lli>> x = consecutive_freq(a,n);
        lli ans=0;
        for(int i=0;i<x.size();i++)
        {
            if(x[i].first == 0)
                ans = max(ans,x[i].second);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

