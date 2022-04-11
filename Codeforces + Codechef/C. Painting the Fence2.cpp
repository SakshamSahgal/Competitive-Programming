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

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,q;
    cin>>n>>q;
    vector<vector<int>> v(n+1);
    vector<vector<unsigned int>> h(q+1,vector<unsigned int>(q+1));
    lli taken = 0;
    for(int i=1; i<=q; i++)
    {
        lli l,r;
        cin>>l>>r;
        for(int j=l; j<=r; j++)
            v[j].push_back(i);
    }

    for(auto &&i:v)
    {
        if(i.size() != 0)
        {
            taken++;
            sort(i.begin(),i.end());
        }
    }

    //Vec_2d_printer(v);

    for(lli i=1; i<=n; i++)
    {
        if(v[i].size() == 1)
            h[v[i][0]][0]++;
        if(v[i].size() == 2)
            h[v[i][0]][v[i][1]]++;
    }

    lli maxx = -inf;
    for(lli i=1; i<=q; i++)
    {
        for(lli j=i+1; j<=q; j++)
        {
            lli rem = taken - h[i][0] - h[j][0] - h[i][j];
            //cout<<"taking {"<<i<<" "<<j<<"} "<<rem<<"\n";
            maxx = max(maxx,rem);
        }
    }
    cout<<maxx<<"\n";
    return 0;
}

