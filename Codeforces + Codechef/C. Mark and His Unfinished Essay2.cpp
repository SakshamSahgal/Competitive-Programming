#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;


lli get_id(vector<pll> &v,lli k)
{
    lli l=0;
    lli h=v.size()-1;
    while(l <= h)
    {
        lli mid = (l+h)/2;
        if(  v[mid].first <= k && k <= v[mid].second )
            return mid;
        else if(k < v[mid].first)
            h = mid-1;
        else
            l = mid+1;
    }
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
        lli n,c,q;
        cin>>n>>c>>q;
        string s;
        cin>>s;
        vector<pll> v;
        v.push_back({1,n});
        map<pll,pll> ft;
        lli st=n+1;
        while(c--)
        {
            lli l,r;
            cin>>l>>r;
            v.push_back({st,st+r-l});
            ft[{st,st+r-l}] = {l,r};
            st += r-l+1;
        }

        while(q--)
        {
            lli k;
            cin>>k;
            while(k > n)
            {
                lli id = get_id(v,k);
                lli st = ft[v[id]].first;
                k = st + k - v[id].first;
            }
            cout<<s[k-1]<<"\n";
        }

        t--;
    }
    return 0;
}

