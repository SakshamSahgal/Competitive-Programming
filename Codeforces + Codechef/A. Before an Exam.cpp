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

        lli n,s;
        cin>>n>>s;
        vector<pair<lli,lli>> v(n);
        lli mn=0;
        lli mx=0;
        lli a[n];
        for(int i=0;i<n;i++)
        {
            cin>>v[i].first>>v[i].second;
            mn += v[i].first;
            mx += v[i].second;
        }

        if(mn <= s && s <= mx)
        {
            cout<<"YES\n";
            for(int i=0;i<n;i++)
                a[i] = v[i].first;
            s -= mn;
            for(int i=0;i<n;i++)
            {
                if(s == 0)
                    break;
                lli mf = v[i].second - v[i].first;
                a[i] += min(mf,s);
                s -= min(mf,s);
            }

            for(int i=0;i<n;i++)
                cout<<a[i]<<" ";
            cout<<"\n";
        }
        else
            cout<<"NO\n";

    return 0;
}

