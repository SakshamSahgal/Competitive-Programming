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

bool solve(string aa,string bb,lli n,lli m)
{
    map<char,lli> fa;
    map<char,lli> fb;

    for(auto i:aa)
        fa[i]++;
    for(auto i:bb)
        fb[i]++;

    lli rem = max(n,m) - min(n,m);

    lli noo=0;
    lli noe=0;

    for(auto i:fb)
    {
        if(fa[i.first] < i.second)
        {
            return 0;
        }
        else
            fa[i.first] -= i.second;
    }


    for(auto i:fa)
    {
        if(i.second%2)
            noo++;
        else
            noe++;
    }

    if(rem%2)
    {
        if(noo == 1)
            return 1;
        else
            return 0;
    }
    else
    {
        if(noo == 0)
            return 1;
        else
            return 0;
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
        lli n,m;
        cin>>n>>m;
        string a,b;
        cin>>a>>b;

        if(solve(a,b,n,m) || solve(b,a,m,n))
            cout<<"YES\n";
        else
            cout<<"NO\n";



l:
        t--;
    }
    return 0;
}

