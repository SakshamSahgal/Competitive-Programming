#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
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

//remember to use endl instead of \n for interactive problems.

bool intersect(ld x1,ld y1,ld x2,ld y2,ld r1,ld r2)
{
    ld d = sqrtl( (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2) );

    lli mx = max(r1,r2);
    lli mn = min(r1,r2);

    if((mx-mn) <= d && d <= mx+mn)
        return 1;
    else
        return 0;
}

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

bool lie(ld x1,ld y1,ld r,ld px,ld py)
{
    if(   (px-x1)*(px-x1) + (py-y1)*(py-y1) == r*r  )
        return 1;
    else
        return 0;
}

bool yes=0;
bool vis[4000];
void dfs(lli v,map<int,vector<int>> &g,lli to)
{
    //cout<<v<<" ";
    vis[v] = 1;
    if(v == to)
        yes = 1;

    for(auto i:g[v])
    {
        if(!vis[i])
            dfs(i,g,to);
    }
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<vector<ld>> a(n,vector<ld>(3));
    ld sx,sy,tx,ty;
    cin>>sx>>sy>>tx>>ty;
    map<int,vector<int>> g;
    lli fr=-1;
    lli to=-1;
    for(int i=0; i<n; i++)
    {
        cin>>a[i][0]>>a[i][1]>>a[i][2];
        if(lie(a[i][0],a[i][1],a[i][2],sx,sy))
            fr = i;
        if(lie(a[i][0],a[i][1],a[i][2],tx,ty))
            to = i;
    }

    //cout<<"from -> "<<fr<<" to -> "<<to<<"\n";
    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            lli x1 = a[i][0];
            lli y1 = a[i][1];
            lli r1 = a[i][2];
            lli x2 = a[j][0];
            lli y2 = a[j][1];
            lli r2 = a[j][2];
            if(intersect(x1,y1,x2,y2,r1,r2))
            {
                g[i].push_back(j);
                g[j].push_back(i);
            }
        }
    }

    //display(g);

    dfs(fr,g,to);
    if(yes)
        cout<<"Yes\n";
    else
        cout<<"No\n";

    return 0;
}
