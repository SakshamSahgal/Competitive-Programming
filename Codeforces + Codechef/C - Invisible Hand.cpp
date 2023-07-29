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


bool poss(vector<lli> &a,vector<lli> &b,lli x)
{
    lli nog=0;
    lli nos=0;
    auto ptr1 = lower_bound(b.begin(),b.end(),x);
    if(ptr1 != b.end())
    {
        lli id1 = ptr1 - b.begin();
        nos = b.size() - id1;
    }

    auto ptr2 = upper_bound(a.begin(),a.end(),x);
    lli id2 = ptr2 - a.begin();
    nog = id2;

    return (nog >= nos);
}

int main()
{
    GO_FAST
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

    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    lli l=0;
    lli h=1e12;
    lli ans=-1;
    while(l<=h)
    {
        lli mid=(l+h)/2;
        if(poss(a,b,mid))
            ans = mid,h=mid-1;
        else
            l=mid+1;
    }
    cout<<ans<<"\n";
    return 0;
}

