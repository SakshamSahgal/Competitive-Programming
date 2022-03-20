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

lli flip_it(lli n){
    lli no = 0,cnt = 0;
    while(n){
        if(n%2 == 0) no += (1LL<<cnt);
        n /= 2,cnt++;
        if(n <= 0) break;
    }
    return no;
}

int main()
{
    GO_FAST
    //cout<<(2<<1)<<"\n";
    int t;
    cin>>t;

    while(t)
    {
        lli n;
        cin>>n;
        lli ans = 0;
        while(n > 0)
        {
            lli a = flip_it(n);
            lli b = n;
            if((b&(b+1)) == 0) b--;
            lli val = ((b * (b+1)) / 2) - ((a * (a-1)) / 2);
            ans += (val*2);
            n = a-1;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

