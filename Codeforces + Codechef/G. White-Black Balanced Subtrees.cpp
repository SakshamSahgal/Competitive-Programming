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

//remember to use endl instead of \n for interactive problems.


pair<lli,lli> dfs(lli v,vector<vector<lli>> &g,string &col,lli &cu)
{
    //cout<<v<<" ";
    pair<lli,lli> c;

    for(auto i:g[v])
    {
        pair<lli,lli> z = dfs(i,g,col,cu);
        c.first += z.first;
        c.second += z.second;
    }


    //cout<<"at = "<<v<<" got = "<<c.first<<" , "<<c.second<<"\n";
    if(col[v-1] == 'W' && c.second - c.first == 1)
        cu++;
    if(col[v-1] == 'B' && c.first - c.second == 1)
        cu++;

    if(col[v-1] == 'W')
        return {c.first+1,c.second};
    else
        return {c.first,c.second+1};
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
        lli n;
        cin>>n;
        lli a[n+1];
        vector<vector<lli>> g(n+1);
        a[0] = -1;
        a[1] = -1;
        for(lli i=2;i<=n;i++)
        {
            cin>>a[i];
            g[a[i]].push_back(i);
        }
        string col;
        cin>>col;
        lli c=0;
        dfs(1,g,col,c);
        cout<<c<<"\n";
        t--;
    }
    return 0;
}

