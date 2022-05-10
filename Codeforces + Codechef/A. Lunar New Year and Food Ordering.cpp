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

    lli n,m;
    cin>>n>>m;
    set<pair<lli,lli>> p; //cost,index
    lli a[n];
    lli c[n];

    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<n; i++)
        cin>>c[i];

    for(int i=0; i<n; i++)
        p.insert({c[i],i});

    while(m--)
    {
        lli t,d;
        cin>>t>>d;
        t--;
        lli s=0;
        if(a[t] >= d)
        {
            //cout<<"ava\n";
            s += c[t]*d;
            a[t] -= d;
            if(a[t] == 0)
            {
                pair<lli,lli> my_pair = {c[t],t};
                p.erase(p.find(my_pair));
            }
            cout<<s<<"\n";
        }
        else
        {
            s += c[t]*a[t];
            d -= a[t];
            a[t] = 0;
            pair<lli,lli> my_pair = {c[t],t};

            auto ptr = p.find(my_pair);

            if(ptr != p.end())
                p.erase(ptr);

            while(p.size() != 0 && d != 0)
            {
                auto ptr = p.begin();
                lli id = ptr->second;
                //cout<<"cheapest index = "<<id<<"\n";

                if(a[id] >= d)
                {
                    s += d*c[id];
                    a[id] -= d;
                    d = 0;
                    if(a[id] == 0)
                    {
                        my_pair = {c[id],id};
                        ptr = p.find(my_pair);
                        if(ptr != p.end())
                            p.erase(ptr);
                    }
                    break;
                }
                else
                {
                    s += a[id]*c[id];
                    d -= a[id];
                    a[id] = 0;
                    my_pair = {c[id],id};
                    auto ptr = p.find(my_pair);
                    if(ptr != p.end())
                        p.erase(ptr);
                }
            }

            if(p.size() == 0 && d != 0)
                cout<<0<<"\n";
            else
                cout<<s<<"\n";
        }

    }
    return 0;
}
