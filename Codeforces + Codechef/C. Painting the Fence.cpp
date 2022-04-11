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



int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,m;
    cin>>n>>m;
    map<lli,vector<lli>> g;
    map<pair<lli,lli>,lli> h;
    lli h[m+1][m+1];

    for(lli i=0; i<=m; i++)
        for(lli j=0; j<=m; j++)
            h[i][j] = 0;

    lli taken=0;
    for(lli i=1; i<=m; i++)
    {
        lli l,r;
        cin>>l>>r;
        for(lli j=l; j<=r; j++)
            g[j].push_back(i);
    }

    // display(g); //col->painters

    for(auto &&i:g)
    {
        sort(i.second.begin(),i.second.end());
        taken++;
    }


    for(auto i:g)
    {
        if(i.second.size() == 1)
            h[i.second[0]][0]++;
        else if(i.second.size() == 2)
            h[i.second[0]][i.second[1]]++;
    }

    //for(auto i:h)
    // cout<<" {"<<i.first.first<<" "<<i.first.second<<"} -> "<<i.second<<"\n";

    lli maxx = -inf;
    for(lli i=1; i<=m; i++)
    {
        for(lli j=i+1; j<=m; j++)
        {
            lli rem = taken - h[i][0] - h[j][0] - h[i][j];
            //cout<<"taking {"<<i<<" "<<j<<"} "<<rem<<"\n";
            maxx = max(maxx,rem);
        }
    }

    cout<<maxx<<"\n";

    return 0;
}
