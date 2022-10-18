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



map<pair<pair<lli,lli>,pair<lli,lli>>,lli> dp;

lli rec(lli fa,lli la,lli fb,lli lb,lli n,lli m,lli a[],lli b[],lli k,lli mov)
{
    //cout<<"fa = "<<fa<<" la = "<<la<<" fb = "<<fb<<" lb = "<<lb<<"\n";
    lli aa = 0;
    lli bb = 0;
    lli cc = 0;
    lli dd = 0;
    pair<pair<lli,lli>,pair<lli,lli>> x = {{fa,la},{fb,lb}};

    if(dp.find(x) != dp.end())
        return dp[x];

    if(mov < k)
    {
        if(fa <= la)
            aa = a[fa] + rec(fa+1,la,fb,lb,n,m,a,b,k,mov+1);
        if(la >= fa)
            bb = a[la] + rec(fa,la-1,fb,lb,n,m,a,b,k,mov+1);
        if(fb <= lb)
            cc = b[fb] + rec(fa,la,fb+1,lb,n,m,a,b,k,mov+1);
        if(lb >= fb)
            dd = b[lb] + rec(fa,la,fb,lb-1,n,m,a,b,k,mov+1);
    }
    lli maxx = max(max(aa,bb),max(cc,dd));
    dp[x] = maxx;
    return maxx;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    lli c = 1;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];
        lli m;
        cin>>m;
        lli b[m];
        for(int i=0; i<m; i++)
            cin>>b[i];
        lli k;
        cin>>k;

        cout<<"Case #"<<(c++)<<": "<<rec(0,n-1,0,m-1,n,m,a,b,k,0)<<"\n";\
        dp.clear();
        t--;
    }
    return 0;
}
