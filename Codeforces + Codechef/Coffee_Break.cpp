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
typedef pair<lli,lli> pll;


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    priority_queue<pll,vector<pll>,greater<pll>> pq; //min_heap (ava,pg)
    lli n,m,d;
    cin>>n>>m>>d;
    vector<lli> a(n,0);
    vector<lli> b(n,0);
    for(int i=0; i<n; i++)
        cin>>a[i];
    b = a;
    sort(a.begin(),a.end());

    lli ans=0;
    map<lli,lli> pg_no;
    for(int i=0; i<n; i++)
    {
        if(!pq.empty() && pq.top().first <= a[i]) //if available page
        {
            pll mini = pq.top();
            pq.pop();
            pg_no[a[i]] = mini.second;
            if(a[i] + d + 1 <= m) //for next numbers
              pq.push({a[i] + d + 1,mini.second});
        }
        else
        {
            ans++;
            if(a[i] + d + 1 <= m)
                pq.push({a[i]+d+1,ans});
            pg_no[a[i]] = ans;
        }
    }
    cout<<ans<<"\n";
    for(int i=0;i<n;i++)
        cout<<pg_no[b[i]]<<" ";
    cout<<"\n";
    return 0;
}
