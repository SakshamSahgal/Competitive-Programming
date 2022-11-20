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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l > r)
        return 0;
    if(l == 1)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    lli a[n+1]={0};
    lli b[n+1]={0};
    vector<lli> ps(n+1,0);

    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        ps[i] = (i == 1) ? a[i] : a[i] + ps[i-1];
    }

    set<lli> id;
    multiset<lli> sums;
    id.insert(0);
    id.insert(n+1);
    sums.insert(ps[n]);

    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        auto nxt = id.lower_bound(b[i]);
        auto prev = nxt;
        prev--;
        lli prev_id = (*prev);
        lli nxt_id = (*nxt);
       // cout<<"th = "<<b[i]<<" prev = "<<prev_id<<" nxt id = "<<nxt_id<<"\n";
        lli s = sum_btw(ps,prev_id+1,nxt_id-1);
        lli s1 = sum_btw(ps,prev_id+1,b[i]-1);
        lli s2 = sum_btw(ps,b[i]+1,nxt_id-1);

        sums.erase(sums.find(s));
        sums.insert(s1);
        sums.insert(s2);
        id.insert(b[i]);
        cout<<(*sums.rbegin())<<"\n";
    }
    return 0;
}

