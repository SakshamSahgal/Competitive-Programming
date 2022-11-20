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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
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
        lli n,q;
        cin>>n>>q;
        lli a[n];
        map<lli,vector<lli>> ps;
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            for(lli j=0; j<60; j++)
            {
                lli temp = a[i];
                lli is_set = (temp>>j)%2;
                ps[j].push_back(is_set);
            }
        }

        for(auto &&i:ps)
        {
            for(lli j=1; j<i.second.size(); j++)
                i.second[j] += i.second[j-1];
        }

        /*
        cout<<"\n";
        for(auto i:ps)
        {
            for(auto j:i.second)
                cout<<j<<" ";
            cout<<"\n";
        } */

        while(q--)
        {
            lli k,l1,r1,l2,r2;
            cin>>k>>l1>>r1>>l2>>r2;

            l1--;
            r1--;
            l2--;
            r2--;

            lli noo1 = sum_btw(ps[k],l1,r1);
            lli noz1 = r1 - l1 + 1 - noo1;

            lli noo2 = sum_btw(ps[k],l2,r2);
            lli noz2 = r2 - l2 + 1 - noo2;
            lli ans=0;
            ans += (noo1*noz2);
            ans += (noz1*noo2);
            //cout<<noo1<<" "<<noz1<<" "<<noo2<<" "<<noz2<<"\n";
            cout<<ans<<"\n";
        }
        t--;
    }
    return 0;
}

