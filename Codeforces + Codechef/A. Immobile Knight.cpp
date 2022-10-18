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

bool poss(lli i,lli j,lli n,lli m)
{
    if(i >=0 && i < n && j >= 0 && j < m)
        return 1;
    else
        return 0;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli x[n][m];
        for(lli i=0;i<n;i++)
        {
            for(lli j=0;j<m;j++)
            {
                if( !poss(i-2,j-1,n,m) && !poss(i-2,j+1,n,m) && !poss(i+2,j-1,n,m) &&  !poss(i+2,j+1,n,m) && !poss(i-1,j-2,n,m)  && !poss(i-1,j+2,n,m) && !poss(i+1,j-2,n,m)  && !poss(i+1,j+2,n,m) )
                {
                    cout<<i+1<<" "<<j+1<<"\n";
                    goto l;
                }
            }
        }
        cout<<1<<" "<<1<<"\n";
        l:
        t--;
    }
    return 0;
}

