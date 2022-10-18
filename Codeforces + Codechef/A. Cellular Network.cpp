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

bool exist(pll z,vector<lli> &b)
{
    lli l=0;
    lli h = b.size()-1;
    while(l<=h)
    {
        lli mid = (l+h)/2;
        if(z.first <= b[mid] && b[mid] <= z.second)
            return 1;
        else if(b[mid] < z.first)
            l = mid+1;
        else
            h = mid-1;
    }
    return 0;
}


bool possible(lli r,vector<lli> &a,vector<lli> &b)
{
    for(int i=0;i<a.size();i++)
    {
        pll th = {a[i]-r,a[i]+r};
        if(!exist(th,b))
            return 0;
    }
    return 1;
}
int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    vector<lli> a(n);
    vector<lli> b(m);

    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<m;i++)
        cin>>b[i];
    lli l = 0;
    lli h = 1e18;
    lli ans=1e18;
    while(l<=h)
    {
        lli mid = (l+h)/2;
        //cout<<"trying  r = "<<mid<<"\n";
        if(possible(mid,a,b))
        {
            //cout<<"poss\n";
            ans = min(mid,ans);
            h = mid-1;
        }
        else
            l = mid+1;
    }
    cout<<ans<<"\n";
    return 0;
}
