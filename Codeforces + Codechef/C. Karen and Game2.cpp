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



int main()
{
    //GO_FAST

    lli n,m;
    cin>>n>>m;
    lli g[n][m];
    for(int i=0; i<n; i++)
        for(int j=0; j<m; j++)
            cin>>g[i][j];

    lli ans=0;
    vector<pair<char,pair<lli,lli>>> moves;
    if(n <= m) //rows first
    {
        for(int i=0; i<n; i++)
        {
            lli mini = inf;

            for(int j=0; j<m; j++)
                mini = min(mini,g[i][j]);

            if(mini != 0)
            {
                ans += mini;
                moves.push_back({'R',{mini,i+1}});
                for(int j=0; j<m; j++)
                    g[i][j] -= mini;
            }
        }

        for(int j=0; j<m; j++)
        {
            lli same = g[0][j];
            for(int i=0; i<n; i++)
            {
                if(same != g[i][j])
                {
                    cout<<"-1\n";
                    return 0;
                }
            }

            if(same != 0)
            {
                ans += same;
                moves.push_back({'C',{same,j+1}});
            }
        }
    }
    else
    {
        for(int j=0; j<m; j++)
        {
            lli mini = inf;
            for(int i=0; i<n; i++)
                mini = min(mini,g[i][j]);

            if(mini != 0)
            {
                ans += mini;
                moves.push_back({'C',{mini,j+1}});
                for(int i=0; i<n; i++)
                    g[i][j] -= mini;
            }


        }

        for(int i=0; i<n; i++)
        {
            lli same = g[i][0];
            for(int j=0; j<m; j++)
            {
                if(same != g[i][j])
                {
                    cout<<"-1\n";
                    return 0;
                }
            }

            if(same != 0)
            {
                ans += same;
                moves.push_back({'R',{same,i+1}});
            }
        }
    }

    cout<<ans<<"\n";
    for(auto i:moves)
    {
        // cout<<i.first<<" "<<i.second.first<<" "<<i.second.second<<"\n";
        for(int j=0; j<i.second.first; j++)
        {
            if(i.first == 'R')
                cout<<"row "<<i.second.second<<"\n";
            else
                cout<<"col "<<i.second.second<<"\n";
        }
    }
    return 0;
}

