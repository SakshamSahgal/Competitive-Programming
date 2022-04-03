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

void set_pair_printer(set<pair<lli,lli>,greater<pair<lli,lli>>> x)
{
    cout<<"\n---------------------------\n";
    for(auto i:x)
        cout<<" { "<<i.first<<" "<<i.second<<" }";
    cout<<"\n---------------------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,x;
        cin>>n>>x;
        set<pair<lli,pair<lli,lli>>> s;
        bool found=0;
        lli maxx_d = -inf;
        while(n--)
        {
            lli d,h;
            cin>>d>>h;
            s.insert({(h-d),{d,h}});
            maxx_d = max(maxx_d,d);
        }

        //set_pair_printer(s);

        lli mp_d = (*s.begin()).second.first;
        lli mp_h = (*s.begin()).second.second;

        if(maxx_d >= x)
            cout<<1<<"\n";
        else
        {
            if(mp_d > mp_h)
            {
                lli moves;
                if( (x - maxx_d )%(mp_d - mp_h) == 0)
                    moves = (x - maxx_d )/(mp_d - mp_h);
                else
                    moves = (x - maxx_d )/(mp_d - mp_h) + 1;

                moves += 1;
                cout<<moves<<"\n";
            }
            else
                cout<<"-1\n";
        }

        t--;
    }
    return 0;
}
