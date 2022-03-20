#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<deque>
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

vector<lli> bits_set(lli n)
{
    vector<lli> x;
    for(lli i=0;i<=15;i++)
    {
        lli set_a = (n>>i)%2;
        if(set_a)
            x.push_back(i);
    }
    return x;
}

void erase_occourances(lli x,map<lli,set<lli>> &g)
{
    vector<lli> occ = bits_set(x);
    for(auto i:occ)
        g[i].erase(g[i].find(x));
}

bool have_same_bit_set(lli a,lli b)
{
    for(lli i=0;i<=15;i++)
    {
        lli set_a = (a>>i)%2;
        lli set_b = (b>>i)%2;
        if(set_a && set_b)
            return 1;
    }
    return 0;
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        set<lli> h;
        map<lli,set<lli>> g;
        for(lli i=0;i<n;i++)
        {
            h.insert(i);
            for(lli j=0;j<=15;j++)
            {
                lli set_bit = (i>>j)%2;
                if(set_bit)
                    g[j].insert(i);
            }
        }
        vector<pair<lli,lli>> ans;
        deque<lli> u;
        for(auto i:bits_set(k))
        {
            cout<<"for bit "<<i<<" ";
            if(g[i].size() >= 2)
            {
                auto ptr = g[i].begin();
                lli a = *ptr;
                ptr++;
                lli b = *ptr;
                cout<<"taking = "<<a<<" "<<b<<"\n";
                h.erase(h.find(a));
                h.erase(h.find(b));
                ans.push_back({a,b});
                erase_occourances(a,g);
                erase_occourances(b,g);
            }
            else
            {
                cout<<"-1\n";
                goto l;
            }
        }

        for(auto i:h)
            u.push_back(i);

        while(u.size()!=0)
        {
            lli a = u.front();
            lli b = u.back();
            if(have_same_bit_set(a,b))
            {
                cout<<"-1\n";
                goto l;
            }
            else
            {
                ans.push_back({a,b});
                u.pop_front();
                u.pop_back();
            }
        }
        for(auto i:ans)
            cout<<i.first<<" "<<i.second<<"\n";
        l:
        t--;
    }
    return 0;
}

