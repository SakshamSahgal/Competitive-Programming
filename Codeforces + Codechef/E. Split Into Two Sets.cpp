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


bool fail=0;
void DFS(lli v,bool vis[],map<lli,vector<lli>> &g,lli depth[],lli d,lli p)
{

    vis[v] = 1;
    depth[v] = d;
    //cout<<v<<" "<<" depth = "<<depth[v]<<"\n";
    for(auto i:g[v])
    {
        if(!vis[i])
            DFS(i,vis,g,depth,d+1,v);
        else
        {
            if(i != p)
            {
                lli len = abs(d - depth[i]) + 1;
                //cout<<"cycle det "<<len<<" from "<<v<<" ending at "<<i<<"\n";
                if(len%2)
                    fail = 1;
            }
        }
    }
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
        bool vis[n+1] = {0};
        lli depth[n+1] = {0};
        map<lli,vector<lli>> g;
        fail = 0;
        for(int i=0; i<n; i++)
        {
            lli a,b;
            cin>>a>>b;
            g[a].push_back(b);
            g[b].push_back(a);
        }

        for(auto i:g)
        {
            if( (i.second.size()) >= 3)
            {
                fail = 1;
                break;
            }
        }

        if(!fail)
        {
            for(int i=1; i<=n; i++)
            {
                if(!vis[i])
                {
                    //cout<<"going "<<i<<"\n";
                    DFS(i,vis,g,depth,1,-1);
                    if(fail)
                        break;
                }
            }

        }


        if(fail)
            cout<<"NO\n";
        else
            cout<<"YES\n";

        t--;
    }
    return 0;
}
