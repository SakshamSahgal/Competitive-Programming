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


lli dot_btw_row(lli l,lli r,lli i,vector<vector<lli>> &psr)
{
    if(l == 0)
        return psr[i][r];
    else
        return psr[i][r] - psr[i][l-1];
}

lli dot_btw_col(lli l,lli r,lli j,vector<vector<lli>> &psr)
{
    if(l == 0)
        return psr[r][j];
    else
        return psr[r][j] - psr[l-1][j];
}


lli try_horizontal(lli i,lli j,lli n,vector<string> &v,vector<vector<lli>> &psr)
{
    if(j+5 < n)
       return dot_btw_row(j,j+5,i,psr);
    else
        return inf;
}

lli try_vertical(lli i,lli j,lli n,vector<string> &v,vector<vector<lli>> &psc)
{
    if(i+5 < n)
       return dot_btw_col(i,i+5,j,psc);
    else
        return inf;
}

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


lli try_diagonal1(lli i,lli j,lli n,vector<string> &v)
{
    lli c=0;
    if(i+5 < n && j+5 < n)
    {
        if(v[i][j] == '.')
            c++;
        if(v[i+1][j+1] == '.')
            c++;
        if(v[i+2][j+2] == '.')
            c++;
        if(v[i+3][j+3] == '.')
            c++;
        if(v[i+4][j+4] == '.')
            c++;
        if(v[i+5][j+5] == '.')
            c++;
        return c;
    }
    else
        return inf;
}

lli try_diagonal2(lli i,lli j,lli n,vector<string> &v)
{
    lli c=0;
    if(i+5 < n && j-5 >= 0)
    {
        if(v[i][j] == '.')
            c++;
        if(v[i+1][j-1] == '.')
            c++;
        if(v[i+2][j-2] == '.')
            c++;
        if(v[i+3][j-3] == '.')
            c++;
        if(v[i+4][j-4] == '.')
            c++;
        if(v[i+5][j-5] == '.')
            c++;
        return c;
    }
    else
        return inf;
}

int main()
{
    //GO_FAST
    lli n;
    cin>>n;
    vector<string> v(n);
    vector<vector<lli>> psr(n,vector<lli>(n));
    vector<vector<lli>> psc(n,vector<lli>(n));
    lli sum=0;

    for(int i=0;i<n;i++)
        cin>>v[i];

    for(int i=0;i<n;i++)
    {
        sum = 0;
        for(int j=0;j<n;j++)
        {
            if(v[i][j] == '.')
                sum++;
            psr[i][j] = sum;
        }
    }

    for(int i=0;i<n;i++)
    {
        sum=0;
        for(int j=0;j<n;j++)
        {
            if(v[j][i] == '.')
                sum++;
            psc[j][i] = sum;
        }
    }

    //Vec_2d_printer(psr);
    //Vec_2d_printer(psc);

    lli ans=INT_MAX;

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            lli hz = try_horizontal(i,j,n,v,psr);
            lli vt = try_vertical(i,j,n,v,psc);
            lli dg1 = try_diagonal1(i,j,n,v);
            lli dg2 = try_diagonal2(i,j,n,v);
            //cout<<"i = "<<i<<" j  = "<<j<<" "<<"hori = "<<hz<<" vert = "<<vt<<" diag1 = "<<dg1<<" dg2 = "<<dg2<<"\n";
            ans = min(min(min(hz,vt),min(dg1,dg2)),ans);
        }
    }

    if(ans > 2)
        cout<<"No\n";
    else
        cout<<"Yes\n";

    return 0;
}
