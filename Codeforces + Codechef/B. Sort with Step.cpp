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
        lli n,k;
        cin>>n>>k;
        lli a[n];
        vector<pll> x;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            x.push_back({a[i],i});
        }
        sort(x.begin(),x.end());

        vector<pll> z;

        for(int i=0;i<n;i++)
        {
            lli ps = x[i].second%k;
            lli ns = i%k;
            if(ps != ns)
                z.push_back({ps,ns});
        }

        if(z.size() == 0)
            cout<<"0\n";
        else if(z.size() == 2)
        {
            if(z[0].first == z[1].second && z[0].second == z[1].first)
                cout<<"1\n";
            else
                cout<<"-1\n";
        }
        else
            cout<<"-1\n";

        t--;
    }
    return 0;
}

