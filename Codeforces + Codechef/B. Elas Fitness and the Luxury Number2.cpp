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
        lli st,ed;
        cin>>st>>ed;
        lli l=1;
        lli h=1e9;
        lli a,b; //a->greatest sq <= st , b->greatest sq <= ed
        while(l<=h)
        {
            lli mid = (l+h)/2;
            if(mid*mid <= st)
            {
                a = mid*mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }

        l=1;
        h=1e9;

        while(l<=h)
        {
            lli mid = (l+h)/2;
            if(mid*mid <= ed)
            {
                b = mid*mid;
                l = mid+1;
            }
            else
                h = mid-1;
        }

        lli lena = sqrtl(a);
        lli lenb = sqrtl(b);
        lli ans = (sqrtl(b) - sqrtl(a) + 1)*3;
        //cout<<"a = "<<a<<" b = "<<b<<"\n";


        if(st > a + 2*lena)
            ans -= 3;
        else if(st > a + lena)
            ans -= 2;
        else if(st > a)
            ans -= 1;

        if(ed >= b + 2*lenb)
            ans -= 0;
        else if( ed >= b + lenb)
            ans -= 1;
        else if(ed >= b)
            ans -= 2;

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}


