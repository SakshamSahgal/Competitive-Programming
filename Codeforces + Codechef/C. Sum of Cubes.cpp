#include<bits/stdc++.h>
#define lli long long int
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
    int t;
    cin>>t;
    while(t)
    {
        lli x;
        cin>>x;

        for(lli i=1;i<10000;i++)
        {
            lli l = 1;
            lli h = 10000;
            while(l <= h)
            {
                lli mid = (l+h)/2;
                lli z = i*i*i + mid*mid*mid;
                if(z == x)
                {
                    cout<<"YES\n";
                    goto l;
                }
                else if(z < x)
                    l = mid+1;
                else
                    h = mid-1;
            }
        }
        cout<<"NO\n";
        l:
        t--;
    }
    return 0;
}

