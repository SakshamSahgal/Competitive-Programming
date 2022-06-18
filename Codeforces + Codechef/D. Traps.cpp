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
        vector<pair<lli,lli>> v;
        lli s=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s += a[i];
            v.push_back({a[i] - n + i + 1,i});
        }
        sort(v.begin(),v.end(),greater<pair<lli,lli>>());
        //for(auto i:v)
        //cout<<" {"<<i.first<<" , "<<i.second<<"}\n";;
        for(int i=0;i<k;i++)
            s -= v[i].first;
        s -= (k*(k-1)/2);
        cout<<s<<"\n";
        t--;
    }
    return 0;
}
