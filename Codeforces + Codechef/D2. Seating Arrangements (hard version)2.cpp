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

pair<lli,lli> no_to_index(lli no,lli n,lli m)
{
    lli i,j;
    if(no%m == 0)
        i = no/m - 1;
    else
        i = no/m;

    j = no - i*m - 1;
    //cout<<i<<" "<<j<<"\n";
    pair<lli,lli> p;
    p.first = i;
    p.second = j;
    return p;
}

lli count_it(vector<vector<lli>> &vv,lli ii,lli jj)
{
    lli c=0;
    for(int j=0; j<jj; j++)
    {
        if(vv[ii][j])
            c++;
    }
    return c;
}

void arrange_vec(vector<lli> &v,lli n,lli m)
{
    vector<lli> re_Arranged;
    map<lli,vector<lli>> row_wise;

    for(int i=0; i<v.size(); i++)
        row_wise[no_to_index(v[i],n,m).first].push_back(v[i]);

    for(auto &&i:row_wise)
        sort(i.second.begin(),i.second.end(),greater<lli>());

    for(auto i:row_wise)
    {
        for(auto j:i.second)
            re_Arranged.push_back(j);
    }


    v.clear();
    v = re_Arranged;
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
        lli a[(n*m)];
        lli b[(n*m)];
        vector<vector<lli>> vv(n,vector<lli>(m));

        for(int i=0; i<(n*m); i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }
        sort(a,a+(n*m));
        lli no=1;

        map<lli,vector<lli>> g;

        for(int i=0; i<(n*m); i++)
            g[a[i]].push_back(i+1);
        display(g);
        lli ans=0;
        for(lli i=0; i<(n*m); i++)
        {
            auto ptr = g[b[i]].begin();
            lli ii = (no_to_index(((ptr->second)),n,m)).first;
            lli jj = (no_to_index(((ptr->second)),n,m)).second;
            vv[ii][jj] = 1;
            ans += count_it(vv,ii,jj);
            g[b[i]].erase(ptr);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

