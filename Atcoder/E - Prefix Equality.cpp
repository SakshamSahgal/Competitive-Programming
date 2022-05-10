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
    lli b[n];

    vector<lli> dist_a(n);
    vector<lli> dist_b(n);

    set<lli> aa;
    set<lli> bb;

    vector<lli> da;
    vector<lli> db;

    for(lli i=0; i<n; i++)
    {
        cin>>a[i];
        aa.insert(a[i]);
        dist_a[i] = aa.size();
        if( i == 0 || dist_a[i] != dist_a[i-1])
            da.push_back(a[i]);
    }


    for(lli i=0; i<n; i++)
    {
        cin>>b[i];
        bb.insert(b[i]);
        dist_b[i] = bb.size();
        if( i == 0 || dist_b[i] != dist_b[i-1])
            db.push_back(b[i]);
    }


    lli maxx = min(da.size(),db.size());

    set<lli> diff;

    vector<lli> ans;

    for(lli i=0; i<maxx; i++)
    {
        auto ptr = diff.find(da[i]);

        if(ptr == diff.end())
            diff.insert(da[i]);
        else
            diff.erase(ptr);

        ptr = diff.find(db[i]);

        if(ptr == diff.end())
            diff.insert(db[i]);
        else
            diff.erase(ptr);

        ans.push_back(diff.size());
    }

    lli q;
    cin>>q;
    while(q--)
    {
        lli x,y;
        cin>>x>>y;
        x--;
        y--;
        if(dist_a[x] != dist_b[y])
            cout<<"No\n";
        else
        {
            lli id = dist_a[x]-1;
            if(ans[id] == 0)
                cout<<"Yes\n";
            else
                cout<<"No\n";
        }
    }
    return 0;
}
