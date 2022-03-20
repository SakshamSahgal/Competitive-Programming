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
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;
        lli b[n] = {0};
        vector<vector<lli>> v(n+1);
        lli ans=0;
        lli mxx;
        if(k%2 == 0)
            mxx = k/2 - 1;
        else
            mxx = k/2;

        for(int i=0; i<= mxx ; i++)
        {
            for(int j=i; j<n; j+=k)
                b[j] = i+1;
            for(int j=n-1-i; j>=0; j-=k)
                b[j] = i+1;
        }
        map<lli,vector<lli>> g;
        for(int i=0;i<n;i++)
            v[b[i]].push_back(i);

        for(int i=1;i<=mxx+1;i++)
        {
            map<char,lli> f;
            for(int j=0;j<v[i].size();j++)
                f[(s[v[i][j]])]++;
            lli maxx = -inf;
            for(auto i:f)
                maxx = max(maxx,i.second);
            ans += v[i].size() - maxx;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

