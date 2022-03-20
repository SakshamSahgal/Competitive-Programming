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
        lli x;
        cin>>x;
        lli a=0,b=0,c=0;
        lli set_bit=0;
        for(lli i=0; i<=27; i++)
        {
            if(((x>>i)%2))
            {
                set_bit = set_bit%3;
                if(set_bit == 0)
                {
                    a += powl(2,i);
                    b += powl(2,i);
                }
                else if(set_bit == 1)
                {
                    b += powl(2,i);
                    c += powl(2,i);
                }
                else
                {
                    c += powl(2,i);
                    a += powl(2,i);
                }
                set_bit++;
            }
            else
            {
                set_bit = set_bit%3;
                if(set_bit == 0)
                    a += powl(2,i);
                else if(set_bit == 1)
                    b += powl(2,i);
                else
                    c += powl(2,i);
                set_bit++;
            }
        }
        cout<<a<<" "<<b<<" "<<c<<"\n";
        t--;
    }
    return 0;
}
