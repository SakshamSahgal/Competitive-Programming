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

//remember to use endl instead of \n for interactive problems.

lli mod=1e9 + 7;

lli mul_mod(lli a,lli b)
{
    return (a*b)%mod;
}

void add_mod(lli &a,lli b)
{
    a += b;
    if(a >= mod)
        a -= mod;
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
        lli n;
        cin>>n;
        lli a[n];
        lli oi=-1;
        lli zi=-1;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            if(a[i] == 1)
                oi = i;
            if(a[i] == 0)
                zi = i;
        }

        if(n == 1)
            cout<<1<<"\n";
        else
        {
            lli mex=-1;
            lli ht[n] = {0};
            lli nbotz = 0;
            for(int i=min(zi,oi); i<=max(zi,oi); i++)
            {
                ht[a[i]] = 1;
                nbotz++;
            }

            nbotz-=2;
            for(int i=0; i<n; i++)
            {
                if(ht[i] == 0)
                {
                    mex = i;
                    break;
                }
            }
            //cout<<mex<<"\n";
            lli ngtm=0;
            for(int i=min(zi,oi); i<=max(zi,oi); i++)
            {
                if(a[i] > mex)
                    ngtm++;
            }

            lli x = min(zi,oi);
            lli y = max(zi,oi);
            lli ntbr=0;
            for(int i=0; i<n; i++)
            {
                if(i < x ||  i > y )
                {
                    if(a[i] > mex)
                      ntbr++;
                }
            }
            //cout<<"mex = "<<mex<<" ngt = "<<ngtm<<" ntbr = "<<ntbr<<"\n";

            if(nbotz == 0)
                cout<<1<<"\n";
            else if(ntbr == 0)
            {
                lli ans=1;
                for(lli i=1;i<=nbotz;i++)
                    ans = mul_mod(ans,i);
                cout<<ans<<"\n";
            }
            else
            {
                lli ans=1;
                for(lli i=1;i<=nbotz;i++)
                    ans = mul_mod(ans,i);
                ans = (((ngtm + 1)%mod)*(ans%mod))%mod;
                ans = mul_mod(ans,ntbr);

                lli fact = 1;
                for(lli i=1;i<=ntbr;i++)
                    fact = mul_mod(fact,i);

                ans = mul_mod(ans,fact);
                cout<<ans<<"\n";
            }
        }

        t--;
    }
    return 0;
}
