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

int main()
{
    GO_FAST

    lli n,m;
    cin>>n>>m;
    vector<vector<lli>> g(n+1);
    set<pair<lli,lli>> f;
    vector<pair<lli,lli>> v;

    for(int i=0; i<m; i++)
    {
        lli x,y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
        v.push_back({x,y});
        f.insert({x,y});
    }

    lli mini =  inf;

    for(int i=0;i<v.size();i++)
        {
            for(int j = i+1;j<=v.size();j++)
            {
                lli a1 = v[i].first;
                lli b1 = v[i].second;
                lli a2 = v[j].first;
                lli b2 = v[j].second;
                lli p1;
                lli p2;
                lli p3;
                bool found=0;
                //cout<<"Edges Picked = "<<a1<<" "<<b1<<" , "<<a2<<" "<<b2<<"\n";
                if(a1 == a2)
                {
                    p1 = a1;
                    p2 = b1;
                    p3 = b2;
                    found = 1;
                }
                else if( b1 == b2 )
                {
                    p1 = b1;
                    p2 = a1;
                    p3 = a2;
                    found = 1;
                }
                else if(a1 == b2)
                {
                    p1 = a1;
                    p2 = a2;
                    p3 = b1;
                    found = 1;
                }
                else if(b1 == a2)
                {
                    p1 = b1;
                    p2 = a1;
                    p3 = b2;
                    found = 1;
                }

                if(found == 1)
                {
                    auto ptr1 = f.find({p2,p3});
                    auto ptr2 = f.find({p3,p2});
                    if(ptr1 != f.end() || ptr2 != f.end() )
                    {
                        lli ans = g[p1].size() + g[p2].size() + g[p3].size() - 6;
                        //cout<<"ans = "<<p1<<" "<<p2<<" "<<p3<<" = "<<ans<<"\n";
                        mini = min(mini,ans);
                    }
                }
            }
        }

    //display_graph(g);
    if(mini == inf)
        cout<<"-1\n";
    else
        cout<<mini<<"\n";
    return 0;
}

