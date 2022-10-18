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




int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;

        lli max_len = -inf;
        map<lli,lli> mx;
        vector<vector<lli>> g(n+1);
        priority_queue<lli,vector<lli>,greater<lli>> pq;
        for(lli i=1;i<=n;i++)
            mx[i] = n;
        while(m--)
        {
            lli x,y;
            cin>>x>>y;
            mx[x] = y;
            g[y].push_back(x);
        }
        lli ans[n+1];
        ans[0] = -inf;
        set<lli> rem;
        set<lli> rem2;
        for(lli i=1;i<=n;i++)
        {
            pq.push(i);
            rem.insert(i);
        }
        for(lli i=1;i<=n;i++)
        {
            for(int j=0;j<g[i].size();j++)
            {
                if(pq.top() <= i)
                {
                    ans[(pq.top())] = g[i][j];
                    rem.erase(rem.find(g[i][j]));
                    pq.pop();
                }
                else
                {
                    cout<<"-1\n";
                    goto l;
                }
            }
        }

        for(auto i:rem)
        {
            ans[pq.top()] = i;
            pq.pop();
        }
        rem.clear();


        for(lli i=1;i<=n;i++)
            rem2.insert(i);

        for(lli i=n;i>=1;i--)
        {
            auto ptr = rem2.upper_bound(mx[i]);
            ptr--;
            rem2.erase(ptr);
            ans[(*ptr)] = i;
        }

        for(lli i=1;i<=n;i++)
            cout<<ans[i]<<" ";
        cout<<"\n";
        l:
        t--;
    }
    return 0;
}

