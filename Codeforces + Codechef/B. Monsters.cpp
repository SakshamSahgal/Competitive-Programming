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


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        lli a[n];
        set<pair<lli,lli>> z;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            z.insert({a[i]%k,i});
        }
        vector<lli> ans;
        vector<pll> zz;
        for(auto i:z)
        {
            if(i.first == 0)
                ans.push_back(i.second+1);
            else
            zz.push_back({i.first,-i.second});
        }

        sort(zz.begin(),zz.end(),greater<pair<lli,lli>>());

        for(auto i:zz)
            ans.push_back(abs(i.second)+1);

        for(auto i:ans)
            cout<<i<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

