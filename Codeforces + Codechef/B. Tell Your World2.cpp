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

void display(map<pair<lli,lli>,vector<pair<lli,lli>>> &x)
{
    for(auto i:x)
    {
        cout<<"{ "<<i.first.first<<"/"<<i.first.second<<" } -> ";
        for(auto j:i.second)
            cout<<" {"<<j.first<<"/"<<j.second<<"} ";
        cout<<"\n";
    }
}

int main()
{
    //GO_FAST

        lli n;
        cin>>n;
        lli y[n];
        set<pair<pair<lli,lli>,pair<lli,lli>>> all;
        map<pair<pair<lli,lli>,pair<lli,lli>>,lli> f;

        for(int i=0; i<n; i++)
            cin>>y[i];

        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                lli num = (y[j]-y[i]);
                lli deno = (j - i);
                lli mn = num/__gcd(abs(num),abs(deno));
                lli md = deno/__gcd(abs(num),abs(deno));
                num = y[i]*md - mn*(i+1);
                deno = md;
                lli cn = num/__gcd(abs(num),abs(deno));
                lli cd = deno/__gcd(abs(num),abs(deno));

                if(cn < 0 && cd < 0)
                {
                    cn = -cn;
                    cd = -cd;
                }

                if(cn > 0 && cd < 0)
                {
                    cn=-cn;
                    cd=-cd;
                }

                if(mn < 0 && md < 0)
                {
                    mn = -mn;
                    md = -md;
                }

                if(mn > 0 && md < 0)
                {
                    mn=-mn;
                    md=-md;
                }

                cout<<" with "<<y[i]<<" & "<<y[j]<<" m = "<<mn<<"/"<<md<<" c = "<<cn<<"/"<<cd<<"\n";
                f[{{mn,md},{cn,cd}}]++;
                all.insert({{mn,md},{cn,cd}});
            }
        }

        map<pair<lli,lli>,vector<pair<lli,lli>>> g;

        for(auto i:all)
            g[i.first].push_back(i.second);

        display(g);

    return 0;
}

