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
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a,b;
        cin>>a>>b;
        lli xora = 0;
        lli xorb = 0;
        lli x = 0;
        for(lli i=n-1; i>=0; i--)
        {
            lli set_a = (a>>i)%2;
            lli set_b = (b>>i)%2;
            lli his_bit;
            if(set_a == 0 && set_b == 0)
                his_bit = 1;
            else if(set_a == 1 && set_b == 1)
                his_bit = 0;
            else
            {
                if(set_a == 0 && set_b == 1)
                {
                    if(xora < xorb)
                        his_bit = 1;
                    else
                        his_bit = 0;
                }
                else
                {
                    if(xora < xorb)
                        his_bit = 0;
                    else
                        his_bit = 1;
                }
            }

            if(his_bit)
                x += powl(2,i);

            if((his_bit^set_a))
                xora += powl(2,i);

            if(his_bit^set_b)
                xorb += powl(2,i);
        }
        cout<<x<<"\n";
        t--;
    }
    return 0;
}
