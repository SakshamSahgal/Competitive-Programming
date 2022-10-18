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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<lli> a(n);
        lli ans=0;
        for(int i=0; i<n; i++)
            cin>>a[i];

        for(lli l=2; l<=n; l*=2) //logn
        {
            for(int i=0; i<n; i+=l)
            {
                lli st = i;
                lli ed = i+l-1;
                vector<lli> z;
                for(lli j=st; j<=ed; j++)
                    z.push_back(a[j]);
                vector<lli> sorted = z;
                sort(sorted.begin(),sorted.end());
                if(sorted[sorted.size()-1] - sorted[0] == l-1)
                {
                    if(sorted != z)
                        ans++;
                    lli x=0;
                    for(lli j=st; j<=ed; j++)
                        a[j] = sorted[x++];
                    }
                else
                {
                    cout<<"-1\n";
                    goto l;
                }
            }
        }
        cout<<ans<<"\n";
l:
        t--;

    }
    return 0;
}

