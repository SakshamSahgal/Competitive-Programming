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

bool poss(lli i,lli j,lli n,lli m)
{
    if(i >= 0 && i < n && j >=0 && j < m)
        return 1;
    else
        return 0;
}

int main()
{
    GO_FAST
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    vector<vector<bool>> vis(n,vector<bool>(m));
    queue<pair<lli,lli>> q;
    lli k;
    cin>>k;
    while(k--)
    {
        lli x,y;
        cin>>x>>y;
        q.push({x-1,y-1});
        vis[x-1][y-1] = 1;
    }
    pair<lli,lli> last_push;
    while(!q.empty())
    {
        pair<lli,lli> tp = q.front();
        q.pop();
        for(int i=-1;i<=1;i++)
        {
            for(int j=-1;j<=1;j++)
            {
                if( abs(i+j) == 1 && poss(tp.first+i,tp.second+j,n,m) )
                {
                    if(!vis[tp.first + i][tp.second + j])
                    {
                        last_push = {tp.first+i,tp.second+j};
                        vis[tp.first + i][tp.second + j] = 1;
                        q.push({tp.first+i,tp.second+j});
                    }
                }
            }
        }
    }
    cout<<last_push.first+1<<" "<<last_push.second+1<<"\n";
    return 0;
}

