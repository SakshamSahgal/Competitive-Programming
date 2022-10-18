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
        lli n,k,r,c;
        cin>>n>>k>>r>>c;
        vector<string> v(n);
        for(int i=0; i<n; i++)
            for(int j=0; j<n; j++)
                v[i] += '.';

        r--;
        c--;
        for(int i=r,cc = c; i>=0; i--,cc = (cc+1)%n)
        {
            lli x = (cc/k);
            for(int j = cc - x*k; j<n; j+=k)
                v[i][j] = 'X';
        }
        for(int i=r,cc=c; i<n; i++)
        {
            lli x = (cc/k);
            for(int j = cc - x*k; j<n; j+=k)
                v[i][j] = 'X';
            cc--;
            if(cc < 0)
                cc += n;
        }
        for(int i=0; i<n; i++)
            cout<<v[i]<<"\n";

        t--;
    }
    return 0;
}
