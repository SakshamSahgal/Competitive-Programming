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
    // GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        map<lli,set<lli>> g;
        lli mx = -inf;
        map<lli,lli> f;
        multiset<lli> ms;
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            ms.insert(a[i]);
            mx = max(mx,a[i]);
            for(lli j=0; j<=32; j++)
            {
                lli temp = a[i];
                lli is_set = (temp>>j)%2;
                if(is_set)
                    g[j].insert(temp);
            }
        }

        vector<lli> ans;
        ans.push_back(mx);
        lli cur_or = mx;

        ms.erase(ms.find(mx));
        bool got=0;

        while(!got)
        {
            for(lli j=0; j<=32; j++)
            {
                lli temp = cur_or;
                lli is_set = (temp>>j)%2;
                if(is_set)
                {
                    got = 1;
                    vector<lli> te;
                    for(auto k:g[j])
                        te.push_back(k);
                    for(auto i:te)
                    {
                        if( ms.find(i) != ms.end())
                            ms.erase(ms.find(i));
                        lli inse = i - powl(2,j);

                        ms.insert(inse);
                    }
                    g[j].clear();
                }
            }
            ans.push_back((*ms.rbegin()));
            cur_or = (cur_or|(*ms.rbegin()));
            auto ptr = ms.end();
            ptr--;
            if(ms.size() != 0)
                ms.erase(ptr);
        }

        for(auto i:ms)
            ans.push_back(i);

        for(auto i:ans)
            cout<<i<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

