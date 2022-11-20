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
    lli n,m;
    cin>>n>>m;
    lli c[n];
    set<lli> dc;
    vector<vector<lli>> cv(1e5+1);
    for(int i=0; i<n; i++)
    {
        cin>>c[i];
        cv[c[i]].push_back(i+1);
        dc.insert(c[i]);
    }

    vector<vector<lli>> g(n+1);

    for(int i=0; i<m; i++)
    {
        lli x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    map<lli,vector<lli>> ans;
    lli mx_sz=-inf;
    for(auto th_col:dc)
    {
        set<lli> q;
        //cout<<"trying col = "<<th_col<<" ";
        for(auto ver:cv[th_col])
        {
            for(auto neig:g[ver])
            {
                if(c[neig-1] != th_col)
                    q.insert(c[neig-1]);
            }
        }
        //cout<<" sz = "<<q.size()<<"\n";
        ans[q.size()].push_back(th_col);
        mx_sz = max(mx_sz,(lli)q.size());
    }

    lli col=inf;

    for(auto i:ans[mx_sz])
        col = min(col,i);

    cout<<col<<"\n";

    return 0;
}

