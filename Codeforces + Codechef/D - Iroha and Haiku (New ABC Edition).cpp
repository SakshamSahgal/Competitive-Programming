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
typedef pair<lli,lli> pii;



vector<pii> window(lli a[],lli n,lli s)
{
    lli l=0;
    lli r=0;
    lli ts=a[0];
    vector<pii> z;
    while(1)
    {
        if(ts == s)
        {
            z.push_back({l,r});
            if(l < r)
            {
                ts -= a[l];
                l++;
            }
            else if(l == r)
            {
                if(r+1 < n)
                {
                    ts = a[r+1];
                    l++;
                    r++;
                }
                else
                    break;
            }
        }
        else if(ts < s)
        {
            if(r+1 < n)
            {
                ts+=a[r+1];
                r++;
            }
            else
                break;
        }
        else if(ts > s)
        {
            if(l < r)
            {
                ts-=a[l];
                l++;
            }
            else if(l == r)
            {
                if(r+1 < n)
                {
                    ts = a[r+1];
                    l++;
                    r++;
                }
                else
                    break;
            }
        }
    }
    return z;
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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,p,q,r;
    cin>>n>>p>>q>>r;
    lli a[n];
    vector<pii> v1;
    vector<pii> v2;
    vector<pii> v3;
    for(int i=0; i<n; i++)
        cin>>a[i];

    v1 = window(a,n,p);
    v2 = window(a,n,q);
    v3 = window(a,n,r);
    //pair_printer(v1);
    //pair_printer(v2);
    //pair_printer(v3);
    for(auto i:v1)
    {
        pii z = {i.second+1,-inf};
        auto ptr = lower_bound(v2.begin(),v2.end(),z);
        if( ptr != v2.end() && (*ptr).first == z.first )
        {
            pii z2 = {(*ptr).second+1,-inf};
            auto ptr2 = lower_bound(v3.begin(),v3.end(),z2);
            if(ptr2 != v3.end() && (*ptr2).first == z2.first)
            {
                //cout<<"{"<<i.first<<" "<<i.second<<"} "<<"{"<<(*ptr).first<<" "<<(*ptr).second<<"} "<<"{"<<(*ptr2).first<<" "<<(*ptr2).second<<"} \n";
                cout<<"Yes\n";
                goto l;
            }
        }
    }
    cout<<"No\n";
    l:
    return 0;
}
