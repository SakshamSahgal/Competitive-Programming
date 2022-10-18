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

//remember to use endl instead of \n for interactive problems.


void dfs(lli i,lli j,vector<string> &v)
{
    lli maxx = 0;
    if(i-1>=0 && j-1>=0)
    {
        if(v[i][j] == '1' || v[i-1][j] == '1' || v[i][j-1] == '1')
        {
            v[i][j] = '0';
            v[i-1][j] = '0';
            v[i][j-1] = '0';
            1 + dfs(i,)
        }

    }


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
        vector<string> v(n);
        for(int i=0; i<n; i++)
            cin>>v[i];


        t--;
    }
    return 0;
}

