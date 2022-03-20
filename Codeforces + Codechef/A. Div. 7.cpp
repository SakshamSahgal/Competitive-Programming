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

lli diff_dig(lli a,lli b)
{
    lli d=0;
    while(a != 0)
    {
        if(a%10 != b%10)
            d++;
        a/=10;
        b/=10;
    }
    return d;
}

lli nod(lli n)
{
    lli d=0;
    while(n !=0 )
    {
        d++;
        n/=10;
    }
    return d;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli mini = inf;
        lli ans=n;
        for(lli i=7;i<=999;i+=7)
        {
            if(nod(i) == nod(n))
            {
                lli x = diff_dig(i,n);
                if( mini >x)
                {
                    mini = x;
                    ans = i;
                }
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
