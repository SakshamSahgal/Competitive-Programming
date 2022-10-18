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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;

    lli n,m;
    cin>>n>>m;
    lli a[n] = {0};
    lli b[n] = {0};
    lli ps[n] = {0};
    for(int i=0; i<n; i++)
        cin>>a[i];
    sort(a,a+n);

//    for(int i=0; i<n; i++)
//        cout<<a[i]<<" ";
//    cout<<"\n";

    for(int i=0; i<n; i++)
        ps[i] = (i == 0)? a[i] : a[i] + ps[i-1];

    for(int i=0; i<m; i++)
    {
        for(int j=i; j<n; j+=m)
        {
            if(j >= m)
                b[j] = b[j-m] + ps[j];
            else
                b[j] = ps[j];
        }
    }

    for(int i=0; i<n; i++)
        cout<<b[i]<<" ";
    cout<<"\n";

    return 0;
}
