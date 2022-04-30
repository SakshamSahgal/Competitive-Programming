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

lli adj[100][100];
bool vis[100];

void display(lli n)
{
    line_printer(20);
    for(int i=1;i<=n;i++)
    {
        cout<<i<<" -> ";
        for(int j=1;j<=n;j++)
        {
            if(adj[i][j] != 0)
            cout<<"{"<<j<<" , "<<adj[i][j]<<"} ";
        }
        cout<<"\n";
    }
    line_printer(20);
}

lli ed_point;
void DFS(lli v,lli n,lli &mini_wt)
{
    //cout<<" at = "<<v<<"\n";

    vis[v] = 1;
    bool no_way = 1;
    for(int j=1;j<=n;j++)
    {
        if(adj[v][j] != 0 && vis[j] == 0)
        {
            mini_wt = min(mini_wt,adj[v][j]);
            no_way = 0;
            DFS(j,n,mini_wt);
        }
    }

    if(no_way)
    {
        //cout<<"end point = "<<v<<"\n";
        ed_point = v;
    }
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    bool end_points[n+1] = {0};
    for(int i=0;i<m;i++)
    {
        lli a,b,w;
        cin>>a>>b>>w;
        end_points[b] = 1;
        adj[a][b] = w;
    }

    //display(n);
    lli c=0;
    lli ans[n+1][3];
    for(int i=1;i<=n;i++)
    {
        if(end_points[i] == 0)
        {
            //cout<<" st = "<<i<<"\n";
            lli mini = 1e9;
            DFS(i,n,mini);
            lli z = c;
            ans[z][0] = i;
            ans[z][1] = ed_point;
            ans[z][2] = mini;
            c++;
           // cout<<"mini = "<<mini<<"\n";
        }
    }

    cout<<c<<"\n";

    for(int i=0;i<c;i++)
        cout<<ans[i][0]<<" "<<ans[i][1]<<" "<<ans[i][2]<<"\n";

   // DFS(5,n);

    return 0;
}
