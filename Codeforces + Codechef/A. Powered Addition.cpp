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

bool check(lli z,vector<lli> a,lli n)
{
    for(int i=1; i<n; i++)
    {
        lli req = 0;
        while(a[i-1] > a[i] + powl(2,req) - 1)
            req++;

        if(req > z)
            return 0;
        else
            a[i] += powl(2,req) - 1;
    }
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
        vector<lli> a(n);
        for(int i=0; i<n; i++)
            cin>>a[i];
        lli l = 0;
        lli h = 31;
        lli ans=31;
        while(l<=h)
        {
            lli mid = (l+h)/2;
            cout<<"Trying - "<<mid<<"\n";
            if(check(mid,a,lli n))
            {
                cout<<"Possible\n";
                h = mid-1;
                ans = mid;
            }
            else
            {
                cout<<"Not Possible\n";
                l = mid+1;
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

