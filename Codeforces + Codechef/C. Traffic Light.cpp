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
        lli n;
        char c;
        cin>>n>>c;
        string s;
        cin>>s;
        map<char,vector<lli>> g;
        for(int i=0;i<n;i++)
            g[s[i]].push_back(i);

        lli mx = -inf;

        for(auto i:g[c])
        {
            auto ptr = lower_bound(g['g'].begin(),g['g'].end(),i);
            lli th = 0;
            if(ptr == g['g'].end())
                th = n - i + g['g'][0];
            else
                th = (*ptr) - i;
            mx = max(mx,th);
        }
        cout<<mx<<"\n";
        t--;
    }
    return 0;
}

