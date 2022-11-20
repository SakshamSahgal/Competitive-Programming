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

lli mx_freq(map<lli,lli> &f)
{
    lli mx=0;
    for(auto i:f)
        mx = max(mx,i.second);
    return mx;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        lli ans=0;
        for(lli i=0;i<n;i++)
        {
            map<char,lli> f;
            lli mxf=0;
            for(lli j=i;j<min(n,i+100);j++)
            {
                f[s[j]]++;
                mxf = max(mxf,f[s[j]]);
                if(mxf <= f.size())
                    ans++;
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

