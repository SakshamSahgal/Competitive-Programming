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
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    lli a[n];
    map<lli,vector<lli>> g;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        g[a[i]].push_back(i);
    }


    lli q;
    cin>>q;

    while(q--)
    {
        lli l,r,x;
        cin>>l>>r>>x;
        l--;
        r--;

        if(g[x].size() == 0)
            cout<<0<<"\n";
        else
        {
            auto st = lower_bound(g[x].begin(),g[x].end(),l);
            auto ed = lower_bound(g[x].begin(),g[x].end(),r+1);
            lli c;
            if(st == g[x].end())
                c=0;
            else if(ed == g[x].end())
            {
                lli id = st - g[x].begin();
                //cout<<"id = "<<id<<"\n";
                c = g[x].size() - id;
            }
            else
            {
                lli st_id = st - g[x].begin();
                lli ed_id = ed - g[x].begin();

                c = ed_id - st_id;
            }

            cout<<c<<"\n";
        }

    }


    return 0;
}
