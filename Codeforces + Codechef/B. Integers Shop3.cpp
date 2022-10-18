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
        lli n;
        cin>>n;
        pair<lli,lli> rr = {-inf,-inf}; //ed,cost
        pair<lli,lli> ll = {inf,inf}; //st,cost
        pair<lli,lli> mxl = {-inf,-inf}; //len , cost
        while(n--)
        {
            lli a,b,c;
            cin>>a>>b>>c;
            rr = max(rr,{b,-c}); //max end point with min cost
            ll = min(ll,{a,c}); //mini starting with minimumm cost
            mxl = max(mxl,{b-a+1,-c}); //max len with mini cost
            lli a1 = abs(rr.second) + (ll.second);
            lli a2 = abs(mxl.second);

            if(mxl.first == rr.first - ll.first + 1)
                cout<<min(a1,a2)<<"\n";
            else
                cout<<a1<<"\n";
        }
        t--;
    }
    return 0;
}

