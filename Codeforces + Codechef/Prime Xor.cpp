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
    int t;
    cin>>t;
    while(t)
    {
        lli x,y;
        cin>>x>>y;
        lli z = (x^y);
        lli a,b,c;
        if(x%2 == 0)
        {
            a = (z^2);
            b = (y^2);
            c = 2;
        }
        else if(y%2 == 0)
        {
            a = 2;
            b = (x^2);
            c = (z^2);
        }
        else
        {
            a = (x^2);
            b = 2;
            c = (y^2);
        }
        vector<lli> h;
        h.push_back(a);
        h.push_back(b);
        h.push_back(c);
        sort(h.begin(),h.end());
        cout<<h[0]<<" "<<h[1]<<" "<<h[2]<<"\n";
        t--;
    }
    return 0;
}

