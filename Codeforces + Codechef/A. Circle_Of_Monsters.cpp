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

void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)

        lli n;
        cin>>n;
        vector<pll> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i].first>>a[i].second;

        lli ans=0;

        for(int i=0; i<n; i++)
        {
            if(i != n-1)
            {
                if(a[i+1].first > a[i].second)
                {
                    ans += a[i+1].first - a[i].second;
                    a[i+1].first = a[i].second;
                }

            else
            {
                if(a[0].first > a[i].second)
                {
                    ans += a[0].first - a[i].second;
                    a[0].first = a[i].second;
                }
            }
        }
        lli mini = inf;

        //pair_printer(a);

        for(int i=0;i<n;i++)
            mini = min(mini,a[i].first);
        ans += mini;
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
