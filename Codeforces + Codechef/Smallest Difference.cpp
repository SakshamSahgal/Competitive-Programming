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
        lli x[(n*m)];
        lli sz = n*m - (n-1)*(m-1);
        lli pmn[n*m];
        lli smn[n*m];
        lli pmx[n*m];
        lli smx[n*m];

        for(int i=0;i<n;i++)
        {
            pmn[i] = (i == 0) ? x[i] : min(x[i],pmn[i-1]);
            pmx[i] = (i == 0) ? x[i] : max(x[i],pmx[i-1]);
        }

        for(int i=n-1;i>=0;i--)
        {
            smn[i] = (i == 0) ? x[i] : min(x[i],smn[i+1]);
            smx[i] = (i == 0) ? x[i] : max(x[i],smx[i+1]);
        }
        lli ans = inf;
        for(int i=0;i<(n*m);i++)
        {
            lli j = i+sz-1;
            if(j >= (n*m))
                break;
            else
            {
                lli mn;
                lli mx;
                if(i == 0)
                    mn = smn[j+1];
                else if(j == (n*m-1))
                    mn = pmn[i-1];
                else
                    mn = min(pmn[i-1],smn[j+1]);

                if(i == 0)
                    mx = smx[j+1];
                else if(j == (n*m-1))
                    mx = pmx[i-1];
                else
                    mn = max(pmx[i-1],smx[j+1]);

                ans = min(mx-mn,ans);
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

