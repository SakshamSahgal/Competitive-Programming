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

void display(map<lli,vector<lli>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}

lli pair_Sum(vector<lli> &ps)
{
    lli sum = 0;
    lli n = ps.size();
    for(lli i=n-1; i>=0; i--)
        sum += i*ps[i] - (n-1-i)*ps[i];
    return sum;
}

int main()
{
    //GO_FAST

    lli n,m;
    cin>>n>>m;
    lli a[n][m];
    map<lli,vector<lli>> x;
    map<lli,vector<lli>> y;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin>>a[i][j];
            x[a[i][j]].push_back(i);
            y[a[i][j]].push_back(j);
        }
    }

    for(auto &&i:x)
        sort(i.second.begin(),i.second.end());

    for(auto &&i:y)
        sort(i.second.begin(),i.second.end());
    //display(x);
    //display(y);
    lli ans=0;

    for(auto i:x)
        ans += pair_Sum(i.second);

    for(auto i:y)
        ans += pair_Sum(i.second);
        cout<<ans<<"\n";
    return 0;
}

