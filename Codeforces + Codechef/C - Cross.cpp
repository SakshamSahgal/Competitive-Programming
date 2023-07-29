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

bool isIn(lli i,lli j,lli h,lli w)
{
    return (i >=0 && i<h && j>=0 && j<w);
}

bool poss(lli i,lli j,vector<vector<char>> &x,lli n,lli h,lli w)
{
    for(int k=-1;k<=1;k+=2)
    {
        for(int l=-1;l<=1;l+=2)
        {
            if(!isIn(i+(n+1)*k,j+(n+1)*l,h,w))
                return 1;
            else if(isIn(i+(n+1)*k,j+(n+1)*l,h,w) && x[i+(n+1)*k][j+(n+1)*l] == '.')
                return 1;
        }
    }
    return 0;
}

lli mx(vector<vector<char>> &x,lli ii,lli jj,lli h,lli w)
{
    lli c[4] = {0};
    lli cc=0;

    for(int k=-1;k<=1;k+=2)
    {
        for(int l=-1;l<=1;l+=2)
        {
            lli i = ii;
            lli j = jj;
            while(isIn(i,j,h,w))
            {
                if(x[i][j] == '#')
                {
                    c[cc]++;
                    i+=k;
                    j+=l;
                }
                else
                    break;
            }
            c[cc]--;
            cc++;
        }
    }

    if(poss(ii,jj,x,min({c[0],c[1],c[2],c[3]}),h,w))
        return min({c[0],c[1],c[2],c[3]});
    else
        return 0;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli h,w;
    cin>>h>>w;
    vector<vector<char>> x(h,vector<char>(w));

    for(int i=0; i<h; i++)
        for(int j=0; j<w; j++)
            cin>>x[i][j];


    /*
    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(x[i][j] == '#')
                cout<<mx(x,i,j,h,w)<<" ";
        }
        cout<<"\n";
    } */

    map<lli,lli> f;

    for(int i=0; i<h; i++)
    {
        for(int j=0; j<w; j++)
        {
            if(x[i][j] == '#')
                f[mx(x,i,j,h,w)]++;
        }
    }

    for(lli i=1;i<=min(h,w);i++)
        cout<<f[i]<<" ";

    return 0;
}

