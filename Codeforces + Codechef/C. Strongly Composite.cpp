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

set<lli> factors(lli n)
{
    set<lli> factors;
    for(int i=1;i<=sqrt(n);i++)
    {
        if(n%i == 0)
        {
            factors.insert(i);
            factors.insert(n/i);
        }
    }
    return factors;
}

void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i:x)
        cout<<i<<" ";
    cout<<"\n---------------------------\n";
}
bool is_prime(lli n) //sqrt(n)
{
    bool flag = 1;
    for(lli i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    if (n <= 1)
        flag = 0;

    return flag;
}

bool scc(lli n)
{
    set<lli> z = factors(n);
    //set_printer(z);
    lli pd=0;
    lli cd=0;
    for(auto i:z)
    {
        if(i != 1)
        {
            if(is_prime(i))
                pd++;
            else
                cd++;
        }
    }
    return (pd <= cd);
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;

        for(int i=2;i<=t;i++)
        {
            if(scc(i))
                cout<<i<<"\n";
        }
        t--;

    return 0;
}

