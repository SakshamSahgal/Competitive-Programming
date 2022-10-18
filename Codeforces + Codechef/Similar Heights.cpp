#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
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
    lli t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        map<lli,lli> f;
        lli maxx_max = -inf;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            maxx_max = max(maxx_max,a[i]);
            f[a[i]]++;
        }

        lli c=0;
        lli nmax=-inf;
        lli mmaxx = -1;
        for(auto i:f)
        {
            if(i.second == 1)
            {
                c++;
                mmaxx = max(i.first,mmaxx);
            }
            else
            {
                nmax = max(nmax,i.second);
            }
        }

        lli ans;
        if(c == 1)
        {
            if(mmaxx == maxx_max)
            {
                if(nmax == 2)
                    cout<<2<<"\n";
                else
                    cout<<1<<"\n";
            }
            else
                cout<<1<<"\n";
        }
        else
        {
            if(c%2 == 0)
                ans = c/2;
            else
                ans = c/2 + 1;
            cout<<ans<<"\n";
        }


        t--;
    }
    return 0;
}
