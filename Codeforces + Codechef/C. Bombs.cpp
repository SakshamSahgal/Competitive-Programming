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
    return (abs(a.first) + abs(a.second)) < (abs(b.first) + abs(b.second));
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    vector<pll> v(n);
    lli s= 4*n;
    for(int i=0; i<n; i++)
    {
        cin>>v[i].first>>v[i].second;
        s += 2*( (v[i].first)&&(v[i].second) );
    }

    cout<<s<<"\n";
    sort(v.begin(),v.end(),comp);
    for(auto i:v)
    {
        vector<pair<lli,char>> last_opp;
        lli x = i.first;
        lli y = i.second;
        if(x > 0)
            cout<<1<<" "<<x<<" "<<"R\n",last_opp.insert(last_opp.begin(),{x,'L'});
        else if(x < 0)
            cout<<1<<" "<<abs(x)<<" "<<"L\n",last_opp.insert(last_opp.begin(), {abs(x),'R'});
        if(y > 0)
            cout<<1<<" "<<y<<" "<<"U\n",last_opp.insert(last_opp.begin(), {y,'D'});
        else if(y < 0)
            cout<<1<<" "<<abs(y)<<" "<<"D\n",last_opp.insert(last_opp.begin(), {abs(y),'U'});
        cout<<2<<"\n";
        for(auto i:last_opp)
            cout<<1<<" "<<i.first<<" "<<i.second<<"\n";
        cout<<3<<"\n";
    }

    return 0;
}

