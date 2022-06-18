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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l > r)
        return 0;
    if(r >= ps.size())
        r = ps.size()-1;
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
        string s;
        cin>>s;
        vector<lli> ps_o(s.length(),0);
        vector<lli> ps_z(s.length(),0);
        lli oc=0;
        lli zc=0;
        int n = s.length();
        for(int i=0;i<n;i++)
        {
            if(s[i] == '1')
                oc++;
            if(s[i] == '0')
                zc++;
            ps_o[i] = oc;
            ps_z[i] = zc;
        }

        lli ans = inf;

        for(int i=-1;i<n;i++)
        {
            lli oc = 0;
            if(i >= 0)
                oc = ps_o[i];

            lli l = i+1;
            lli h = n;
            lli loc_ans=inf;
            //cout<<"i = "<<i<<" l = "<<l<<" h = "<<h<<"\n";
            while(l <= h)
            {
                lli mid = (l+h)/2;
                lli noz = sum_btw(ps_z,i+1,mid-1);
                lli noo = sum_btw(ps_o,mid,n-1) + oc;
                //cout<<"mid = "<<mid<<" l = "<<l<<" h = "<<h<<" pair = ("<<noz<<" , "<<noo<<") \n";
                if(noz > noo)
                {
                     h = mid-1;
                     loc_ans = min(loc_ans , max(noo,noz));
                }
                else if(noz < noo)
                {
                    l = mid + 1;
                    loc_ans = min(loc_ans , max(noo,noz));
                }
                else
                {
                    loc_ans = min(loc_ans , max(noo,noz));
                    break;
                }
            }
            //cout<<"i = "<<i<<" min cost = "<<loc_ans<<"\n";
            ans = min(ans,loc_ans);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
