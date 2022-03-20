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



int main()
{
    //GO_FAST
        lli n,l,w;
        cin>>n>>l>>w;
        vector<pair<lli,lli>> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i].first;
            a[i].second = a[i].first + w;
        }

        lli ans=0;
        if(a[0].first != 0)
        {
            if( (a[0].first)%w == 0 )
                ans += a[0].first/w;
            else
                ans += a[0].first/w + 1;
        }

        for(int i=0; i<n-1; i++)
        {
            if(a[i+1].first > a[i].second)
            {
                if( (a[i+1].first - a[i].second)%w == 0 )
                    ans += (a[i+1].first - a[i].second)/w;
                else
                    ans += (a[i+1].first - a[i].second)/w + 1;
            }
        }

        if(a[n-1].second < l)
        {
            if( (l - a[n-1].second)%w == 0 )
                ans += (l - a[n-1].second)/w;
            else
                ans += (l - a[n-1].second)/w + 1;
        }

        cout<<ans<<"\n";

    return 0;
}

