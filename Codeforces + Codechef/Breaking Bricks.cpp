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
    while(t)
    {
        lli s;
        cin>>s;
        lli w1,w2,w3;
        cin>>w1>>w2>>w3;
        lli ans=0;
        if(w1 >= w3)
        {
            if( (w1 + w2 + w3) <= s)
                cout<<1<<"\n";
            else if( (w1 + w2) <= s )
                cout<<2<<"\n";
            else
            {
                if(w2+w3 <= s)
                    cout<<2<<"\n";
                else
                    cout<<3<<"\n";
            }
        }
        else
        {
            if( (w1 + w2 + w3) <= s)
                cout<<1<<"\n";
            else if( (w3 + w2) <= s )
                cout<<2<<"\n";
            else
                {
                    if(w2 + w1 <= s)
                        cout<<2<<"\n";
                    else
                        cout<<3<<"\n";
                }
        }
        t--;
    }
    return 0;
}

