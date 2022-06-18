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


bool alive(pair<lli,lli> x,lli l,lli r,lli u,lli d,lli n,lli m)
{
    x.first += d;
    x.first -= u;
    x.second += r;
    x.second -= l;

    if(x.second < 0 || x.second >= m || x.first < 0 || x.first >= n)
        return 0;
    else
        return 1;
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
        vector<string> v(n);
        vector<pair<lli,lli>> ra;
        for(int i=0;i<n;i++)
            cin>>v[i];
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(v[i][j] == 'R')
                ra.push_back({i,j});
            }
        }

        for(int i=0;i<ra.size();i++)
        {
            lli l = ra[i].second;
            lli r = 0;
            lli u = ra[i].first;
            lli d = 0;
            bool fail=0;
            for(int j=0;j<ra.size();j++)
            {
                if(i != j)
                {
                    if(!alive(ra[j],l,r,u,d,n,m))
                    {
                        fail = 1;
                        break;
                    }
                }
            }
            if(!fail)
            {
                cout<<"YES\n";
                goto l;
            }
        }
        cout<<"NO\n";
        l:
        t--;
    }
    return 0;
}
