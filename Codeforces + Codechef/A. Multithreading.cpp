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

bool vis[100001];
lli c=0;
void dfs(lli v,lli st,map<lli,vector<lli>> &g)
{
    cout<<v<<" ";
    vis[v] = 1;

    for(auto i:g[v])
    {
        if(i == st)
        {
            cout<<"st found\n";
            c++;
        }


        if(!vis[i])
            dfs(i,st,g);
    }

}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

        lli n;
        cin>>n;
        lli a[n+1];
        lli pos = -1;
        map<lli,vector<lli>> g;
        for(int i=1;i<=n;i++)
            cin>>a[i];


        for(int i=1;i<=n;i++)
            g[a[a[i]]].push_back(a[i]);

        display(g);

        for(int i=1;i<=n;i++)
        {
            if( !vis[i] )
            {
                cout<<"Going in "<<i<<" \n";
                dfs(i,i,g);
            }

        }

        cout<<c<<"\n";
    return 0;
}
