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

lli to_set(lli n)
{
    for(lli i=20; i>=0; i--)
    {
        lli set_a = ((n>>i)&((lli)1));
        if(set_a)
            return i+1;
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
        lli n;
        cin>>n;
        lli st = to_set(n);
        //for(int i=1; i<=n; i++)
            //cout<<i<<" ";
        //cout<<"\n";
        lli maxx = -inf;
        for(int i=1; i<=n; i++)
        {
            lli with = (1<<st);

            lli b = (i^with);
            maxx = max(b,maxx);
            //cout<<b<<" ";

        }
        cout<<maxx<<"\n";
        cout<<"\n";
        t--;
    }
    return 0;
}

