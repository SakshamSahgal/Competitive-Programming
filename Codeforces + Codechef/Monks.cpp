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


bool check(lli a[],lli mid,lli n)
{
    lli s=0;
    for(lli i=n-1;i>=n-mid;i--)
        s += a[i];

    lli req=0;
    lli to = a[n-mid-1];
    for(int i=0;i<n-mid;i++)
        req += abs(to - a[i]);

    if(req <= s)
        return 1;
    else
        return 0;
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
        lli a[n];
        multiset<lli> z;
        map<lli,lli> f;
        for(int i=0;i<n;i++)
            cin>>a[i];

        sort(a,a+n);
        lli l=0;
        lli h=n-1;
        lli ans=0;
        while(l<=h)
        {
            lli mid = (l+h)/2;
            if(check(a,mid,n))
            {
                //cout<<"posssible "<<mid<<"\n";
                h = mid-1;
                ans = mid;
            }
            else
            {
                l = mid+1;
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

