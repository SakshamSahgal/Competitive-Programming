#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

lli mod(lli a,lli b)
{
    lli ret = a % b;
    if (ret < 0)
        ret += b;
    return ret;
}

vector<vector<char>> modify(vector<vector<char>> v,lli s,lli t,lli h,lli w) //v,h
{
    vector<vector<char>> temp(h,vector<char>(w));

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            temp[i][j] = v[mod(i-s,h)][j];

    v = temp;

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
            temp[i][j] = v[i][mod(j-t,w)];
    }

    return temp;
}


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli h,w;
    cin>>h>>w;
    vector<vector<char>> a(h,vector<char>(w));
    vector<vector<char>> b(h,vector<char>(w));

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin>>a[i][j];

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin>>b[i][j];

    for(lli s=0; s<=h; s++)
    {
        for(lli t=0; t<=w; t++)
        {
            if(b == modify(a,s,t,h,w))
            {
                cout<<"Yes\n";
                goto l;
            }
        }
    }
    cout<<"No\n";
    l:
    return 0;
}

