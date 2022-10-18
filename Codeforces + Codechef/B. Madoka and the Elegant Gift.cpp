#include<bits/stdc++.h>
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
typedef pair<lli,lli> pll;

lli minir = inf;
lli maxxr = -inf;
lli minic = inf;
lli maxxc = -inf;
bool is_poss(lli i,lli j,lli n,lli m)
{
    if(i >= 0 && i < n && j >= 0 && j < m)
        return 1;
    else
        return 0;
}

void dfs(lli i,lli j,lli n,lli m,vector<string> &v,vector<vector<bool>> &vis)
{
    vis[i][j] = 1;
    minir = min(minir,i);
    maxxr = max(maxxr,i);
    minic = min(minic,j);
    maxxc = max(maxxc,j);
    if(is_poss(i+1,j,n,m) && v[i+1][j] == '1' && vis[i+1][j] == 0)
        dfs(i+1,j,n,m,v,vis);
    if(is_poss(i,j+1,n,m) && v[i][j+1] == '1' && vis[i][j+1] == 0)
        dfs(i,j+1,n,m,v,vis);
    if(is_poss(i-1,j,n,m) && v[i-1][j] == '1' && vis[i-1][j] == 0)
        dfs(i-1,j,n,m,v,vis);
    if(is_poss(i,j-1,n,m) && v[i][j-1] == '1' && vis[i][j-1] == 0)
        dfs(i,j-1,n,m,v,vis);
}


void Display(map<lli,vector<lli>> g)
{
    cout<<"\n----------------------\n";

    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n----------------------\n";
}

bool check(lli mnr,lli mxr,lli mnc,lli mxc,vector<string> &v)
{
    for(int i=mnr;i<=mxr;i++)
    {
        for(int j=mnc;j<=mxc;j++)
            if(v[i][j] == '0')
                return 0;
    }
    return 1;
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
        lli n,m;
        cin>>n>>m;
        vector<string> v(n);
        vector<vector<bool>> vis(n,vector<bool>(m,0));
        for(int i=0; i<n; i++)
            cin>>v[i];

        lli c=1;
        map<lli,vector<lli>> x;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(v[i][j] == '1' && vis[i][j] == 0)
                {
                    minir = inf;
                    maxxr = -inf;
                    minic = inf;
                    maxxc = -inf;
                    dfs(i,j,n,m,v,vis);
                    x[c].push_back(minir);
                    x[c].push_back(maxxr);
                    x[c].push_back(minic);
                    x[c].push_back(maxxc);
                    c++;
                }
            }
        }
        //Display(x);

        for(auto i:x)
        {
            if(!check(i.second[0],i.second[1],i.second[2],i.second[3],v))
            {
                cout<<"NO\n";
                goto l;
            }
        }
        cout<<"YES\n";
        l:
        t--;
    }
    return 0;
}

