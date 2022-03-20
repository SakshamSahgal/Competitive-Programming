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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        char a[n+1];
        for(int i=1;i<=n;i++)
            cin>>a[i];

        lli p[n+1] = {0};
        lli s=0;

        for(lli i=1;i<=n;i++)
        {
            s += (a[i] - '0');
            p[i] = s;
        }
        //array_printer(a,n+1);
        //array_printer(p,n+1);
        map<lli,lli> f;
        lli ans=0;
        for(lli i=1;i<=n;i++)
        {
            if(p[i] == i)
                ans++;
            ans += f[ p[i]- i ];
            f[ p[i] - i ]++;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

