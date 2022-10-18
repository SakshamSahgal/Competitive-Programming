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




int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n;
    cin>>n;
    lli a[n];
    lli b[n];
    for(lli i=0; i<n; i++)
        cin>>a[i];

    lli ans=inf;
    for(lli i=0; i<n; i++)
    {
        b[i] = 0;
        lli x;
        lli moves = 0;
        for(lli j=i; j>0; j--)
        {
            x = b[j]/a[j-1] - 1;
            b[j-1] = x*(a[j-1]);
            moves += abs(x);
        }
        for(lli j=i; j<n-1; j++)
        {
            x = b[j]/a[j+1] + 1;
            b[j+1] = x*a[j+1];
            moves += abs(x);
        }
        //cout<<moves<<"\n";
        ans = min(ans,moves);
        //array_printer(b,n);
    }
    cout<<ans<<"\n";
    return 0;
}

