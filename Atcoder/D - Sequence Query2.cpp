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



int main()
{
    GO_FAST
    int t;
    cin>>t;
    multiset<lli> xx;
    while(t)
    {
        lli c;
        cin>>c;
        if(c == 1)
        {
            lli x;
            cin>>x;
            xx.insert(x);
        }
        else if(c == 2)
        {
            lli x,k;
            cin>>x>>k;
            auto ptr = xx.upper_bound(x);

            for(int i=1; i<=k; i++)
            {
                ptr--;
                if(ptr == xx.begin() && i != k)
                {
                    cout<<"-1\n";
                    goto l;
                }
            }
            cout<<(*ptr)<<"\n";
        }
        else
        {
            lli x,k;
            cin>>x>>k;
            auto ptr = xx.lower_bound(x);

            if(ptr == xx.end())
            {
                cout<<"-1\n";
                goto l;
            }

            for(int i=1; i<=k-1; i++)
            {
                ptr++;
                if(ptr == xx.end())
                {
                    cout<<"-1\n";
                    goto l;
                }
            }

            cout<<*ptr<<"\n";
        }
l:
        t--;
    }
    return 0;
}

