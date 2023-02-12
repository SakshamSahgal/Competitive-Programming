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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
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
        lli a[n]; //budget
        lli c[m+1]; //bonus
        lli f[m+1] = {0}; //freq hash
        vector<lli> ps(m+1,0);

        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }

        for(int i=1;i<=m;i++)
            cin>>c[i];

        for(int i=1;i<=m;i++)
            ps[i] = f[i] + ps[i-1];

        lli ans=0;

        for(lli i=1;i<=m;i++)
        {
            lli j=1;
            lli qt=0;
            while(1)
            {
                lli l = j*i;
                lli r = min((j+1)*i-1,m);
                //cout<<"i = "<<i<<" l = "<<l<<" r = "<<r<<"\n";
                qt += sum_btw(ps,l,r)*j;
                if(r == m)
                    break;
                j++;
            }
            //cout<<(qt*c[i])<<"\n";
            ans = max(ans,qt*c[i]);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

