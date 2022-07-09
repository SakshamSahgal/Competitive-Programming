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

void ms_printer(multiset<lli> s)
{
    line_printer(20);
    for(auto i:s)
        cout<<i<<" "; 
    line_printer(20);
}

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

bool checker(lli t,map<lli,lli> &f,lli n)
{
    lli rem = 0;
    for (int i = 1; i <= n; i++)
    {
        if (f[i] >= t)
            rem += (f[i] - t);
        else
            rem -= (t - f[i]) / 2;
    }

    if (rem <= 0)
        return 1;
    else
        return 0;
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
        lli n,m;
        cin>>n>>m;
        lli a[m];
        map<lli,lli> f;
        multiset<lli> ms;
        lli ans=m;
        for(int i=0;i<m;i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }

        lli l=1;
        lli h=m;
    
        while(l<=h)
        {
            lli mid = (l + h) / 2;
            if (checker(mid, f,n))
            {
                h = mid - 1;
                ans = mid;
            }
            else
                l = mid+1;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}