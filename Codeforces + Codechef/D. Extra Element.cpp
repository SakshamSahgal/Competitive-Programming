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

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}


int main()
{
    GO_FAST
    lli n;
    cin>>n;
    lli a[n+1];
    map<lli,vector<lli>> orig_index;

    for(lli i=1; i<=n; i++)
    {
        cin>>a[i];
        orig_index[a[i]].push_back(i);
    }
    //display(orig_index);
    if(n <= 3)
    {
        cout<<1<<"\n";
        goto l;
    }
    else
    {
        a[0] = -inf;
        sort(a,a+n+1);
        map<lli,lli> f;
        for(lli i=1; i<=n-1; i++)
            f[(a[i+1] - a[i])]++;

        //Map_printer(f);

        for(lli i=1; i<=n; i++)
        {
            if(i == 1)
            {
                lli d1 = a[i+1] - a[i];

                f[d1]--;

                if(f[d1] == 0)
                    f.erase(f.find(d1));

                //Map_printer(f);

                if(f.size() == 1)
                {
                    cout<<orig_index[a[i]][0]<<"\n";
                    goto l;
                }
                else
                    f[d1]++;
            }
            else if(i == n)
            {
                lli dl = a[i] - a[i-1];
                f[dl]--;

                if(f[dl] == 0)
                    f.erase(f.find(dl));
                //Map_printer(f);
                if(f.size() == 1)
                {
                    cout<<orig_index[a[i]][0]<<"\n";
                    goto l;
                }
                else
                    f[dl]++;
            }
            else
            {
                lli db = a[i] - a[i-1];
                lli df = a[i+1] - a[i];
                lli dn = db + df;

                f[dn]++;
                f[db]--;

                if(f[db] == 0)
                    f.erase(f.find(db));

                f[df]--;

                if(f[df] == 0)
                    f.erase(f.find(df));

                //Map_printer(f);

                if(f.size() == 1)
                {
                    cout<<orig_index[a[i]][0]<<"\n";
                    goto l;
                }
                else
                {
                    f[dn]--;

                    if(f[dn] == 0)
                        f.erase(f.find(dn));
                    f[db]++;
                    f[df]++;
                }
            }
        }
    }
    cout<<"-1\n";
l:
    return 0;
}

