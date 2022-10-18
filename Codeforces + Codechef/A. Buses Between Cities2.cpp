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
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli a,ta,b,tb;
    cin>>a>>ta>>b>>tb;
    string tm;
    cin>>tm;
    lli hr = (lli)stoi(tm.substr(0,2));
    lli mn = (lli)stoi(tm.substr(3,2));
    lli stma = 60*hr + mn;
    lli edma = min((lli)1440,stma+ta);
    //cout<<"stma = "<<stma<<" edma = "<<edma<<"\n";
    lli bb = 300;
    lli ans = 0;
    while(bb < 1440)
    {
        if(bb >stma-tb && bb < edma)
            ans++;
        bb+=b;
    }
    cout<<ans<<"\n";
    return 0;
}
