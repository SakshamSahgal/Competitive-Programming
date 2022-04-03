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



int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,m;
    cin>>n>>m;
    lli b[m+1];
    lli a[n+1];
    lli c[n+m+1];

    for(lli i=n; i>=0; i--)
        cin>>a[i];

    for(lli i=(n+m); i>=0; i--)
        cin>>c[i];

    for(lli i=0; i<=m; i++)
    {
        if(i == 0)
        {
            if(a[0] == 0)
                b[i] = 0;
            else
                b[i] = c[0]/a[0];
        }

        else
        {
            lli sum = 0;
            for(lli j=0,k=i-1; j<i; j++,k--)
            {
                if(j+1 < n+1 && k < (m+1))
                    sum += (a[j+1]*b[k]);
            }
            if(a[0] == 0)
                b[i] = 0;
            else
            b[i] = (c[i] - sum)/a[0];
        }
    }

    for(lli i=m; i>=0; i--)
        cout<<b[i]<<" ";
    cout<<"\n";

    return 0;
}

