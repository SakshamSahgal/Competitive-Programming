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

lli lcm(lli a,lli b)
{
    lli z = (a*b)/__gcd(a,b);
    return z;
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
        lli b[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        for(int i=0;i<n;i++)
            cin>>b[i];

        lli la[n];
        lli lb[n];

        la[0] = a[0];
        lb[n-1] = b[n-1];

        for(int i=1;i<n;i++)
            la[i] = lcm(a[i],la[i-1]);

        for(int i=n-2;i>=0;i--)
            lb[i] = lcm(b[i],lb[i+1]);

        //array_printer(la,n);
        //array_printer(lb,n);

        lli z = max(la[n-1],lb[0]);

        for(int i=0;i<n-1;i++)
        {
            lli h = lcm(la[i],lb[i+1]);
            z = max(z,h);
        }
        cout<<z<<"\n";
        t--;
    }
    return 0;
}
