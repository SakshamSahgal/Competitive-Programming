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
        lli n,m;
        cin>>n>>m;
        string s;
        cin>>s;
        lli noo=0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == '1')
                noo++;
        }


        lli tot = noo*m;
        if(tot%2)
            cout<<0<<"\n";
        else
        {
            if(m != 1)
                s += s;

            if(noo == 0)
            {
                lli zz = (n*m);
                cout<<zz<<"\n";
            }

            else
            {
                lli z = tot/2;
                lli cc;

                if(z%noo == 0)
                    cc = (z/noo - 1)*noo;
                else
                    cc = (z/noo)*noo;

                lli ans=0;
                for(int i=0; i<s.length(); i++)
                {
                    if(s[i] == '1')
                        cc++;
                    if(cc == z)
                        ans++;
                }
                cout<<ans<<"\n";
            }

        }
        t--;
    }
    return 0;
}
