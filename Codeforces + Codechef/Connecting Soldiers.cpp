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


lli prev(lli x,set<lli> &ava)
{
    for(int i=x-1;i>=0;i--)
    {
        if(ava.count(i))
            return i;
    }
}

lli next(lli x,set<lli> &ava,lli n)
{
    for(int i=x+1;i<=n+1;i++)
    {
        if(ava.count(i))
            return i;
    }
}


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    //cout<<is_set(3,2)<<"\n";
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli maxx = ((n+1)*(n+2))/2 - 1;
        lli mini=0;
        set<lli> ava;
        ava.insert(0);
        ava.insert(n+1);
        priority_queue<pair<lli,pair<lli,lli>>> z;
        z.push({n+1,{0,n+1}});

        while(!z.empty())
        {
            mini += z.top().first;
            pair<lli,pair<lli,lli>> tp = z.top();
            z.pop();
            lli th = (tp.second.first + tp.second.second)/2;
            lli pv = prev(th,ava);
            lli nxt = next(th,ava,n);
            ava.insert(th);
            if(th-pv != 1)
                z.push({th-pv,{pv,th}});
            if(nxt-th != 1)
            z.push({nxt-th,{th,nxt}});
        }

        if(m < mini)
            cout<<-1<<"\n";
        else if(m > maxx)
            cout<<m-maxx<<"\n";
        else
            cout<<0<<"\n";
        t--;
    }
    return 0;
}

