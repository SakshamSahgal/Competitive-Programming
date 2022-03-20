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

vector<pair<lli,lli>> prime_factorisation(lli n)
{
    vector<pair<lli,lli>> p;
    if(n == 1)
        return p;
    else
    {
        for(int i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0)
            {
                int c=0;
                while(n%i == 0)
                {
                    n=n/i;
                    c++;
                }
                p.push_back({i,c});
            }
        }

        if(n != 1)
            p.push_back({n,1});

        return p;
    }
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli b,c;
        cin>>b>c;

        t--;
    }
    return 0;
}

