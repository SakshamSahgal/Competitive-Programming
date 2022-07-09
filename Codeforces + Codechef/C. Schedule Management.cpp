#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
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

bool is_possible(lli t,map<lli,lli> &f,lli m,lli n)
{
    lli x = 0;
    lli gg=0;
    lli nt=0;
    for(int i=1;i<=n;i++)
    {
        if(f[i]<t)
        {
            nt++;
            gg+= (t-f[i])/2;
        }
        x += min(f[i],t);
    }

    if(gg+x <= m)
        return 0;

    return 1;
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
        map<lli,lli> f;
        lli a[m];
        multiset<lli> ss;
        lli rem = m;
        lli nof=0;
        lli nob=0;
        for(int i=0; i<m; i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }


        lli l = 1;
        lli h = 1e6;
        lli ans=0;
        for(int i=1;i<=n;i++)
            ans = max(ans,f[i]);
        h = ans;
        while(l<=h)
        {
            lli mid = (l+h)/2;
            cout<<"Trying - "<<mid<<"\n";
            if(is_possible(mid,f,m,n))
            {
                h = mid-1;
                ans = mid;
                cout<<"Possible\n";
            }
            else
            {
                l = mid+1;
                //cout<<"Not Possible\n";
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
