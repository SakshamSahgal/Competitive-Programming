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

lli calc_max_dist(lli n,lli i,lli N)
{
    lli l=1;
    lli h=n;
    lli maxx=1;
    while(l<=h)
    {
        lli mid=(l+h)/2;
        lli lhs = 8*i;
        lli rhs = N*ceil((log2l((long double)mid)));
        //cout<<"RHS = "<<rhs<<"\n";
        if(  lhs >= rhs )
        {
            maxx = mid;
            l = mid+1;
        }
        else
             h = mid-1;

    }
    return maxx;
}

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
}

void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}

int main()
{
    //GO_FAST
    lli n,i;
    cin>>n>>i;

    map<lli,lli> f;

    lli a[n];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        f[a[i]]++;
    }
    lli maxx_dist = calc_max_dist((f.size()),i,n);
    //cout<<"maxx dist = "<<maxx_dist<<"\n";
    vector<pair<lli,lli>> v;
    vector<lli> ps;
    lli sum=0;
    for(auto i:f)
    {
        sum += i.second;
        v.push_back({i.first,i.second});
        ps.push_back(sum);
    }
    //pair_printer(v);
    lli ans = inf;
    lli tot_f = sum;
    for(int l=0;l < v.size();l++)
    {
        lli r = l + maxx_dist - 1;

        if( r >= v.size())
            break;
        else
        {
            //cout<<" if l = "<<l<<" r = "<<r<<" then ans = "<<(tot_f - sum_btw(ps,l,r))<<"\n";
            ans = min(ans,(tot_f - sum_btw(ps,l,r)));
        }
    }
    cout<<ans<<"\n";
    return 0;
}
