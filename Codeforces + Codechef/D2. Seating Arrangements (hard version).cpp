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

void display(map<lli,set<lli>> &g)
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

struct ps
{
    lli right_ava;
    lli left_ava;
    bool ava;
    ps()
    {
        right_ava=0;
        left_ava=0;
        ava=1;
    }
};

pair<lli,lli> no_to_index(lli no,lli n,lli m)
{
    pair<lli,lli> p;
    lli i;
    lli j;

    if(no%m == 0)
        i = no/m - 1;
    else
        i = no/m;

    j = no - i*m - 1;

    p.first = i;
    p.second = j;
    //cout<<"{"<<i<<","<<j<<"}\n";
    return p;
}

void display_grid(vector<vector<ps>> &seats)
{
    line_printer(20);
    for(int i=0; i<seats.size(); i++)
    {
        for(int j=0; j<seats[i].size(); j++)
            cout<<" { "<<seats[i][j].left_ava<<" "<<seats[i][j].ava<<" "<<seats[i][j].right_ava<<"} ";
        cout<<"\n";
    }
    line_printer(20);
}

void update_grid(lli ii,lli jj,vector<vector<ps>> &seats)
{
    seats[ii][jj].ava = 0;
    for(lli j=0; j<jj; j++)
        seats[ii][j].right_ava--;

    for(lli j=jj+1; j<seats[0].size(); j++)
        seats[ii][j].left_ava--;
}

lli the_best(set<lli> &v,vector<vector<ps>> &seats)
{
    //right ava->min and left ava->max
    vector<pair<pair<lli,lli>,lli>> cost;
    lli n = seats.size();
    lli m = seats[0].size();
    for(auto j:v)
    {
        lli ii = no_to_index(j,n,m).first;
        lli jj = no_to_index(j,n,m).second;
        lli la = seats[ii][jj].left_ava;
        lli ra = seats[ii][jj].right_ava;
        cost.push_back({{ra,-la},j});
    }
    sort(cost.begin(),cost.end());
    return (cost[0].second);
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        vector<lli> v(n*m);
        lli orig[(n*m)];
        for(int i=0; i<n*m; i++)
        {
            cin>>v[i];
            orig[i] = v[i];
        }
        sort(v.begin(),v.end());

        map<lli,set<lli>> g;

        for(int i=0; i<n*m; i++)
            g[v[i]].insert(i+1);

        //display(g);

        vector<vector<ps>> seats(n,vector<ps>(m));

        for(int i=0; i<n; i++)
        {
            lli la=0;
            lli ra=m-1;
            for(int j=0; j<m; j++,la++,ra--)
            {
                seats[i][j].left_ava = la;
                seats[i][j].right_ava = ra;
            }
        }

        //display_grid(seats);
        lli ans=0;
        for(int i=0; i<(n*m); i++) //1e5
        {
            lli best = the_best(g[orig[i]],seats);
            //cout<<"Best place for "<<orig[i]<<" = "<<best<<"\n";
            lli ii = no_to_index(best,n,m).first;
            lli jj = no_to_index(best,n,m).second;
            //cout<<"cost = "<<(jj - seats[ii][jj].left_ava)<<"\n";
            ans += jj - seats[ii][jj].left_ava;
            update_grid(ii,jj,seats);
            //display_grid(seats);
            auto ptr = g[orig[i]].find(best);
            g[orig[i]].erase(ptr);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

