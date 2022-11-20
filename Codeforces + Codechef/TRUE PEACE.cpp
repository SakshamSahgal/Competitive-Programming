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

lli sosq(lli n)
{
    lli no=0;
    while(n != 0)
    {
        no += (n%10)*(n%10);
        n /= 10;
    }
    return no;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    set<lli> z;
    z.insert(4);
    z.insert(16);
    z.insert(37);
    z.insert(58);
    z.insert(89);
    z.insert(145);
    z.insert(42);
    z.insert(20);

    while(1)
    {
        n = sosq(n);
        if(z.count(n))
        {
            cout<<"false\n";
            break;
        }
        else if(n == 1)
        {
            cout<<"true\n";
            break;
        }
    }

    return 0;
}

