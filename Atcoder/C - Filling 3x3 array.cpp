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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

        lli ans=0;
        lli h1,h2,h3,w1,w2,w3;
        cin>>h1>>h2>>h3>>w1>>w2>>w3;
        for(int i11=1;i11<=(min(w1-2,h1-2));i11++)
        {
            for(int i12=1;i12<=(min(w2-2,h1-2));i12++)
            {
                for(int i21=1;i21<=(min(w1-2,h2-2));i21++)
                {
                    for(int i22=1;i22<=(min(w2-2,h2-2));i22++)
                    {
                        lli i31 = w1 - i11 - i21;
                        lli i32 = w2 - i12 - i22;
                        lli i33 = h3 - i31 - i32;
                        lli i23 = h2 - i21 - i22;
                        lli i13 = h1 - i11 - i12;

                        if(i11 >= 1 && i12 >= 1 && i13>=1 && i21>=1 && i22>=1 && i23>=1 && i31>=1 && i32>=1&& i33>=1)
                        {
                            bool r1 = ((i11 + i12 + i13) == h1);
                            bool r2 = ((i21 + i22 + i23) == h2);
                            bool r3 = ((i31 + i32 + i33) == h3);
                            bool c1 = ((i11 + i21 + i31) == w1);
                            bool c2 = ((i12 + i22 + i32) == w2);
                            bool c3 = ((i13 + i23 + i33) == w3);
                            if(r1&&r2&&r3&&c1&&c2&&c3)
                                ans++;

                        }
                    }
                }
            }
        }
        cout<<ans<<"\n";

    return 0;
}
