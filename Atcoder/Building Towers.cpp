#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;


lli req_for_first(lli x)
{
    for(lli i=0;;i++)
    {
        if(powl(2,i) >= x)
            return (i+1);
    }
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli x,m;
        cin>>x>>m;
        lli yy = req_for_first(x);
        //cout<<yy<<"\n";
        lli have = powl(2,yy-1);
        //cout<<"now have = "<<have<<"\n";
        if(m < yy)
            cout<<0<<"\n";
        else
            cout<<1 + (m-yy)<<"\n";
        t--;
    }
    return 0;
}
