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
        lli a,b,c,d;
        cin>>a>>b>>c>>d;
        lli a1=-1,a2=-1;
        for(lli i=a+1; i<=c; i++)
        {
            lli g = __gcd((a*b),i);
            lli rq = i/g;
            lli mn = (rq*(a*b))/i;
            //cout<<"i = "<<i<<" mn = "<<mn<<" rq = "<<rq<<"\n";
            if(mn > d)
                continue;
            else
            {
                if(mn >= b+1 && mn <= d)
                {
                    a1 = i;
                    a2 = mn;
                    break;
                }
                else
                {
                    lli y;

                    if( (b+1)%mn == 0)
                        y = b+1;
                    else
                        y = ((b+1)/mn + 1)*mn;
                    if(y >= b+1 && y <= d)
                    {
                        a1 = i;
                        a2 = y;
                        break;
                    }
                }
            }
        }
        cout<<a1<<" "<<a2<<"\n";
        t--;
    }
    return 0;
}

