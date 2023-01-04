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
    while(t)
    {
        lli n,m;
        cin>>n>>m;
        lli a[n][m];
        lli b[n][m];
        multiset<lli> ae;
        multiset<lli> ao;
        multiset<lli> be;
        multiset<lli> bo;
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>a[i][j];
                if((i+j)%2)
                    ao.insert(a[i][j]);
                else
                    ae.insert(a[i][j]);
            }
        }
        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                cin>>b[i][j];
                if((i+j)%2)
                    bo.insert(b[i][j]);
                else
                    be.insert(b[i][j]);
            }
        }
        if(n == 1 || m == 1)
        {
            if(a == b)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        else
        {
            if(ao == bo && ae == be)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }
        t--;
    }
    return 0;
}

