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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

lli dp[100000];


void calc_dp(lli st,lli d,vector<lli> &v)
{
    cout<<"at = "<<st<<" with d = "<<d<<"\n";
    dp[st] = d;
    for(int i=st+1; i<v.size(); i++)
    {
        if(v[i] > v[st] && dp[i] < d+1)
            calc_dp(i,d+1,v);
    }
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
        lli n;
        cin>>n;
        for(int i=0; i<1e5; i++)
            dp[i] = 1;
        lli a[n]; //orig
        lli b[n]; //dist
        map<lli,lli> id;  //element -> index

        for(int i=0; i<n; i++)
            cin>>a[i];

        for(int i=0; i<n; i++)
        {
            cin>>b[i];
            id[b[i]] = i+1;
        }

        vector<lli> orig;

        for(int i=0; i<n; i++)
        {
            if(id[a[i]] != 0) //common
                orig.push_back(id[a[i]]);
        }

        auto ptr = unique(orig.begin(),orig.end());
        orig.resize(distance(orig.begin(),ptr));
        vector_printer(orig);

        if(orig.size() == 0 )
            cout<<0<<"\n";
        else
        {
            calc_dp(0,1,orig);
            array_printer(dp,orig.size());
        }


        t--;
    }
    return 0;
}

