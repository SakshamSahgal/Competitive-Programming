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


template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
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
        lli n,k;
        cin>>n>>k;
        lli a[n];
        map<lli,vector<lli>> g;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            g[a[i]].push_back(i);
        }
        sort(a,a+n);
        n = unique(a, a + n) - a;

        vector<vector<lli>> ps(2,vector<lli>(n));
        lli mini = inf;
        lli maxx = -inf;
        //cout<<"w";
        for(lli i=0;i<n;i++)
        {
            mini = min(mini,g[a[i]][0]);
            maxx = max(maxx,g[a[i]][g[a[i]].size()-1]);
            ps[0][i] = mini;
            ps[1][i] = maxx;
        }

        Vec_2d_printer(ps);


        t--;
    }
    return 0;
}

