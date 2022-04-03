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


void display(map<lli,vector<lli>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli b[n];
        map<lli,vector<lli>> g;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            lli max_bit_set = 0;
            for(int j=0; j<=30; j++)
            {
                lli set_bit = (a[i]>>j)%2;
                if(set_bit)
                    max_bit_set = j;
            }
            b[i] = max_bit_set;
            g[max_bit_set].push_back(i);
        }
        lli ans=0;
        //display(g);
        for(int i=0;i<n;i++)
        {
            auto ptr = lower_bound(g[b[i]].begin(),g[b[i]].end(),i+1);
            if(ptr != g[b[i]].end())
            {
                lli index = ptr - g[b[i]].begin();
                //cout<<"index = "<<index<<"\n";
                ans += g[b[i]].size()-index;
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
