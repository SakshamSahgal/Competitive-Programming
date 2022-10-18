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

lli sum_btw(vector<lli> &ps,lli l,lli r)
{
    if(l == 0)
        return ps[r];
    else
        return (ps[r] - ps[l-1]);
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
        lli n,k;
        cin>>n>>k;
        vector<lli> ps(n);
        vector<lli> a(n);
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            ps[i] = (i == 0) ? a[i] : a[i] + ps[i-1];
        }

        lli s=0;

        if(k <= n)
        {
            for(int i=0; i<n-k+1; i++)
            {
                lli j = i + k - 1;
                lli len = j - i + 1;
                s = max((sum_btw(ps,i,j) + (len*(len-1))/2),s);
            }
        }
        else
            s = sum_btw(ps,0,n-1) + (k-n)*n + (n*(n-1))/2;

        cout<<s<<"\n";
        t--;
    }
    return 0;
}
