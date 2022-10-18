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


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    lli counter=1;
    while(t)
    {
        lli r,c,id;
        cin>>r>>c>>id;
        lli x[r][c];
        id--;
        lli ans=0;
        for(int i=0; i<r; i++)
            for(int j=0; j<c; j++)
                cin>>x[i][j];

        for(int j=0;j<c;j++)
        {
            lli mx=-inf;
            for(int i=0;i<r;i++)
            {
                if(i != id)
                    mx = max(mx,x[i][j]);
            }
            ans += max((lli)0,(mx - x[id][j]));
        }
        cout<<"Case #"<<counter<<": "<<ans<<"\n";
        counter++;
        t--;
    }
    return 0;
}

