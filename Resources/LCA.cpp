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


void display_graph(vector<vector<lli>>v)
{
    line_printer(20);
    for(int i=0; i<v.size(); i++)
    {
        cout<<i<<" -> ";
        for(int j=0; j<v[i].size(); j++)
            cout<<v[i][j]<<" ";
        cout<<"\n";
    }
    line_printer(20);
}

class LCA_recursion
{
public :
    bool *vis;
    vector<vector<lli>> g;
    lli a;
    lli b;
    LCA_recursion(lli sz,vector<vector<lli>> &vv,lli aa,lli bb,lli root)
    {
        vis = new bool[sz]; //if sz = n+1 if vertices start from 1
        for(int i=0; i<sz; i++) //important to reset to 0 because by default all is not set to zero
            vis[i] = 0;
        g = vv;
        a = aa;
        b = bb;
        display_graph(vv);
        cout<<"LCA OF "<<a<<" and "<<b<<" is = "<<dfs(root)<<"\n";
    }

    lli dfs(lli v)
    {
        //cout<<v<<" ";
        vis[v] = 1;

        if(v == a || v == b)
            return v;

        lli a=-1;
        lli b=-1;

        for(auto i:g[v])
        {
            if(!vis[i])
            {
                lli x = dfs(i);

                if(x != -1)
                {
                    //cout<<"\ngot "<<x<<" at = "<<v<<"\n";
                    if(a == -1)
                        a = x;
                    else if(b == -1)
                        b = x;

                    if(a != -1 && b != -1)
                        return v;
                }
            }
        }

        if(a != -1)
            return a;
        else if(b != -1)
            return b;
        else
            return -1;
    }


};




int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    vector<vector<lli>> g(n+1); //vertices starting from 1
    for(int i=0; i<n-1; i++)
    {
        lli a,b;
        cin>>a>>b;
        g[a].push_back(b);
        g[b].push_back(a);
    }
    lli a,b;
    cin>>a>>b;
    LCA_recursion(n+1,g,a,b,1); //finds LCA in O(V + E)
    return 0;
}
