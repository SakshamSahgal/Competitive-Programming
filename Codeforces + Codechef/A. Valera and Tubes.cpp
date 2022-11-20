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


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m,k;
    cin>>n>>m>>k;
    lli a[n][m];
    lli cc=0;
    lli ck=1;
    bool pass=0;

    if(k == 1)
    {
        for(int i=0; i<n; i++)
            for(int j=0; j<m; j++)
                a[i][j] = 1;
    }
    else
    {
        for(int i=0; i<n; i++)
        {
            if(i%2 == 0)
            {
                for(int j=0; j<m; j++)
                {
                    a[i][j] = ck;
                    cc++;
                    if(!pass)
                    {
                        if( cc == 2 )
                        {
                            cc=0;
                            ck++;
                            if(ck == k)
                                pass = 1;
                        }
                    }
                }
            }
            else
            {
                for(int j=m-1; j>=0; j--)
                {
                    a[i][j] = ck;
                    cc++;
                    if(!pass)
                    {
                        if( cc == 2 )
                        {
                            cc=0;
                            ck++;
                            if(ck == k)
                                pass = 1;
                        }
                    }
                }
            }
        }
    }




    map<lli,vector<pll>> g;

    for(int i=0; i<n; i++)
    {
        if(i%2 == 0)
        {
            for(int j=0; j<m; j++)
                g[a[i][j]].push_back({i+1,j+1});
        }
        else
        {
            for(int j=m-1; j>=0; j--)
                g[a[i][j]].push_back({i+1,j+1});
        }

    }





    for(auto i:g)
    {
        cout<<i.second.size()<<" ";
        for(auto j:i.second)
            cout<<j.first<<" "<<j.second<<" ";
        cout<<"\n";
    }

    return 0;
}

