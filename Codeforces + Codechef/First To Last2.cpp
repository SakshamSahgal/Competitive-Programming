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

bool comp(pll a,pll b)
{
    return(a.first < b.first && a.second < b.second);
}

void pair_printer(vector<pll> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
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
        lli n,m,k;
        cin>>n>>m>>k;
        map<lli,vector<lli>> z;

        while(k--)
        {
            lli r,c;
            cin>>r>>c;
            if(r < n && c < m)
                z[r].push_back(c);
        }

        for(auto &&i:z)
            sort(i.second.begin(),i.second.end());

        vector<lli> x;
        vector<lli> lis;

        for(auto i:z)
        {
            x.push
        }


        for(lli i=0; i<x.size(); i++)
        {
            auto ptr = lower_bound(lis.begin(),lis.end(),x[i]);
            if(ptr == lis.end())
                lis.push_back(x[i]);
            else
            {
                lli id = ptr - lis.begin();
                lis[id] = x[i];
            }
        }

        lli l=lis.size();
        lli ans = n + m - l - 2;
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
