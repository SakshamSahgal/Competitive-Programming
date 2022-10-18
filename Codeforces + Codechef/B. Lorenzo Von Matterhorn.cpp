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

//remember to use endl instead of \n for interactive problems.


void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

vector<lli> path(lli u,lli v)
{
    vector<lli> pu;
    pu.push_back(u);
    vector<lli> pv;
    pv.push_back(v);

    while(u != v)
    {
        if(u > v)
        {
            u /= 2;
            pu.push_back(u);
        }
        else if( v > u)
        {
            v /=2;
            pv.push_back(v);
        }
    }

    reverse(pv.begin(),pv.end());

    pu.pop_back();
    vector<lli> temp;

    for(auto i:pu)
        temp.push_back(i);

    for(auto i:pv)
        temp.push_back(i);

    return temp;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    map<pair<lli,lli>,lli> wt;
    int t;
    cin>>t;

    while(t)
    {
        lli x,u,v,w;
        cin>>x;
        if(x == 1)
        {
            cin>>u>>v>>w;
            vector<lli> z = path(min(u,v),max(u,v));
            //vector_printer(z);
            for(int i=0; i<z.size()-1; i++)
                wt[ {min(z[i],z[i+1]),max(z[i],z[i+1])} ] += w;
        }
        else
        {
            cin>>u>>v;
            vector<lli> z = path(min(u,v),max(u,v));
            //vector_printer(z);
            lli s=0;
            for(int i=0; i<z.size()-1; i++)
                s += wt[  {min(z[i],z[i+1]),max(z[i],z[i+1])} ] ;
            cout<<s<<"\n";
        }

        t--;
    }
    return 0;
}
