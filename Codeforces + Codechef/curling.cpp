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

bool is_in(lli x,lli y,lli rs,lli rh)
{
    lli ds = x*x + y*y;
    lli sq = (rs+rh)*(rs+rh);
    if(ds <= sq)
        return 1;
    else
        return 0;
}

lli dist(lli x,lli y)
{
    return (x*x + y*y);
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli counter=1;
    int t;
    cin>>t;
    while(t)
    {
        lli rs,rh;
        cin>>rs>>rh;
        int n,m;
        cin>>n;
        vector<pll> rt(n);
        for(int i=0; i<n; i++)
            cin>>rt[i].first>>rt[i].second;
        cin>>m;
        vector<pll> yt(m);
        for(int i=0; i<m; i++)
            cin>>yt[i].first>>yt[i].second;

        vector<pll> innr;
        vector<pll> inny;
        lli y=0,z=0;

        for(int i=0; i<n; i++)
        {
            if(is_in(rt[i].first,rt[i].second,rs,rh))
                innr.push_back(rt[i]);
        }

        for(int i=0; i<m; i++)
        {
            if(is_in(yt[i].first,yt[i].second,rs,rh))
                inny.push_back(yt[i]);
        }

        for(auto i:innr)
        {
            lli rd = dist(i.first,i.second);
            lli ym = inf;
            for(auto j:yt)
                ym = min(ym,dist(j.first,j.second));
            if(rd < ym)
                y++;
        }

        for(auto i:inny)
        {
            lli yd = dist(i.first,i.second);
            lli rm = inf;
            for(auto j:rt)
                rm = min(rm,dist(j.first,j.second));
            if(yd < rm)
                z++;
        }
        cout<<"Case #"<<counter<<": "<<y<<" "<<z<<"\n";
        counter++;
        t--;
    }
    return 0;
}

