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
        lli n,k;
        cin>>n>>k;
        lli a[n];
        lli d[k];
        lli st = n-k;
        for(int i=0; i<k; i++)
            cin>>d[i];

        lli z = d[0]/(n-k+1);
        lli rem=d[0];
        for(int i=0;i<(n-k+1);i++)
        {
            a[i] = z;
            rem -= z;
        }

        if(rem < 0)
            a[0] += rem;
        else
            a[n-k] += rem;

        lli j=1;
        for(int i=n-k+1;i<n;i++,j++)
                a[i] = d[j] - d[j-1];


        array_printer(a,n);

        for(int i=1;i<n;i++)
        {
            if(a[i] < a[i-1])
            {
                cout<<"NO\n";
                goto l;
            }
        }
        cout<<"YES\n";
        l:
        t--;
    }
    return 0;
}

