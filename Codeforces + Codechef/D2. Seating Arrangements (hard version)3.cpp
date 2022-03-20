#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<queue>
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

void transform_it(map<lli,vector<lli>> &g,map<lli,queue<lli>> &xx,lli n,lli m)
{
    for(auto i:g)
    {
        map<lli,vector<lli>> row_wise;

        for(auto j:i.second)
            row_wise[no_to_index(j,n,m).first].push_back(j);

        for(auto &&j:row_wise)
            sort(j.second.begin(),j.second.end(),greater<lli>());

        for(auto j:row_wise)
            for(auto k:j.second)
                xx[i.first].push(k);
    }
}

void display_2(map<lli,queue<lli>> &g)
{
    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        while(!i.second.empty())
        {
            cout<<i.second.front()<<" ";
            i.second.pop();
        }
        cout<<"\n";
    }

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

        map<lli,vector<lli>> g;

        for(int i=0; i<(n*m); i++)
            g[a[i]].push_back(i+1);

        map<lli,queue<lli>> xx;

        transform_it(g,xx,n,m);
        //display_2(xx);
        lli ans=0;
        for(int i=0;i<(n*m);i++)
        {
            lli best = xx[b[i]].front();
            xx[b[i]].pop();
            lli ii = no_to_index(best,n,m).first;
            lli jj = no_to_index(best,n,m).second;
            vv[ii][jj] = 1;
            ans += count_it(vv,ii,jj);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

