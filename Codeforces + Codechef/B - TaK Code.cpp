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

char get_char(lli r,lli c)
{
    char z;
    if( (r <= 3 && c <= 3) || (r >= 7 && c >= 7) )
        z = '#';
    else if( (r == 4 && c <= 4) || (c == 4 && r <= 4) || (r == 6 && c >= 6) || (c == 6 && r >= 6) )
        z = '.';
    else
        z = '?';
    return z;
}

bool pass(lli ii,lli jj,vector<string> &x)
{
    for(lli i=ii,r=1; i<ii+9; i++,r++)
    {
        for(int j=jj,c=1; j<jj+9; j++,c++)
        {
            if(get_char(r,c) != '?' && x[i][j] != get_char(r,c))
                return 0;
        }
    }
    return 1;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,m;
    cin>>n>>m;
    vector<string> v(n);

    for(int i=0;i<n;i++)
        cin>>v[i];

    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(i+8 < n && j+8 < m && pass(i,j,v))
                cout<<i+1<<" "<<j+1<<"\n";

        }

    }
    return 0;
}
