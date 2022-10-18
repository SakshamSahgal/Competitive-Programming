#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.

lli k;

lli dfs(lli v,vector<vector<lli>> &g,vector<lli> &a)
{
    //cout<<v<<" k = "<<k<<"\n";
    if(g[v].size() == 0)
    {
        if(k)
        {
            //cout<<"at "<<v<<" putting "<<1<<"\n";
            a[v] = 1;
            k--;
            return 1;

        }
        else
        {
           // cout<<"at "<<v<<" putting "<<0<<"\n";
            return 0;
        }

    }

    lli s=0;
    for(auto i:g[v])
        s += dfs(i,g,a);

    //cout<<"at "<<v<<" got "<<s<<"\n";

        if(s%2)
        {
            if(k)
            {
                k--;
                a[v] = 0;
                return s;
            }
            else
            {
                a[v] = 1;
                return s+1;
            }
        }
        else
        {
            if(k)
            {
                k--;
                a[v] = 1;
                return s+1;
            }
            else
            {
                return s;
            }
        }

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
        lli n,K;
        cin>>n>>K;
        k = K;
        lli p[n+1];
        vector<lli> a(n+1,0);
        p[1] = -1;

        vector<vector<lli>> g(n+1);
        for(lli i=2; i<=n; i++)
        {
            cin>>p[i];
            g[p[i]].push_back(i);
        }

        dfs(1,g,a);
        for(lli i=1;i<=n;i++)
            cout<<a[i];
        cout<<"\n";
        t--;
    }
    return 0;
}

