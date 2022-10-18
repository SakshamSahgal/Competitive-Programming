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

bool maths(pair<lli,pair<lli,lli>> a,pair<lli,pair<lli,lli>> b)
{
    if(a.second.first < b.second.first)
        return 1;
    else if(a.second.first == b.second.first)
        return (a.first > b.first);
    else
        return 0;
}

bool eng(pair<lli,pair<lli,lli>> a,pair<lli,pair<lli,lli>> b)
{
    if(a.second.second < b.second.second)
        return 1;
    else if(a.second.second == b.second.second)
            return (a.first > b.first);
    else
        return 0;
}
bool tot(pair<lli,pair<lli,lli>> a,pair<lli,pair<lli,lli>> b)
{
    if ( (a.second.first + a.second.second) < ( b.second.first + b.second.second) )
        return 1;
    else if((a.second.first + a.second.second == b.second.first + b.second.second))
        return (a.first > b.first);
    else
        return 0;
}

void printer( vector<pair<lli,pair<lli,lli>>> &v)
{
    for(auto i:v)
        cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
}
int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,x,y,z;
    cin>>n>>x>>y>>z;
    vector<pair<lli,pair<lli,lli>>> v(n);

    for(int i=0; i<n; i++)
    {
        v[i].first = i+1;
        cin>>v[i].second.first;
    }

    for(int i=0; i<n; i++)
        cin>>v[i].second.second;

    sort(v.begin(),v.end(),maths);

    //printer(v);
    vector<lli> ans;
    while(x--)
    {
        //cout<<v[v.size()-1].first<<"\n";
        ans.push_back(v[v.size()-1].first);
        v.pop_back();
    }

    sort(v.begin(),v.end(),eng);

    //printer(v);

    while(y--)
    {
        //cout<<v[v.size()-1].first<<"\n";
        ans.push_back(v[v.size()-1].first);
        v.pop_back();
    }

    sort(v.begin(),v.end(),tot);

    while(z--)
    {
        //cout<<v[v.size()-1].first<<"\n";
        ans.push_back(v[v.size()-1].first);
        v.pop_back();
    }

    sort(ans.begin(),ans.end());
    for(auto i:ans)
        cout<<i<<"\n";
    return 0;
}
