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
    lli n,m;
    cin>>n>>m;
    lli a[n];
    map<pair<lli,lli>,lli> b;
    for(int i=0; i<n; i++)
        cin>>a[i];
    lli ans=0;
    for(lli i=0; i<n-1; i++)
    {
        if(a[i] != a[i+1])
        {
            b[ {i,i+1}] = (i+1)*(n-i-1);
            ans += (i+1)*(n-i-1);
        }

    }
    ans += (n*(n+1))/2;

    while(m--)
    {
        lli i,x;
        cin>>i>>x;
        i--;
        if(a[i] != x)
        {
            if(i != 0)
            {
                if(a[i-1] == a[i]) //no barrack
                {
                    ans += (i)*(n-i);
                    b[ {i-1,i}] = (i)*(n-i);
                }
                else
                {
                    if(a[i-1] == x)
                    {
                        ans -= b[ {i-1,i}];
                        b.erase({i-1,i});
                    }
                }
            }
            if(i != n-1)
            {
                if(a[i] == a[i+1]) //no barrack
                {
                    ans += (i+1)*(n-i-1);
                    b[ {i,i+1}] = (i+1)*(n-i-1);
                }
                else
                {
                    if(x == a[i+1])
                    {
                        ans -=  b[ {i,i+1}];
                        b.erase({i,i+1});
                    }
                }
            }
            a[i] = x;
        }

        cout<<ans<<"\n";
    }

    return 0;
}

