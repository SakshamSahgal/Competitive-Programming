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
    lli t;
    cin>>t;
    lli ct=1;
    while(t)
    {
        lli cmyk[3][4];
        lli a=inf,b=inf,c=inf,d=inf;
        for(lli i=0; i<3; i++)
        {
            cin>>cmyk[i][0]>>cmyk[i][1]>>cmyk[i][2]>>cmyk[i][3];
            a = min(a,cmyk[i][0]);
            b = min(b,cmyk[i][1]);
            c = min(c,cmyk[i][2]);
            d = min(d,cmyk[i][3]);
        }
        cout<<"Case #"<<(ct++)<<": ";
        //cout<<"{"<<a<<" "<<b<<" "<<c<<" "<<d<<"} \n";
        if(a + b + c + d < 1000000)
            cout<<"IMPOSSIBLE\n";
        else
        {
            lli maxx[4];
            maxx[0] = a;
            maxx[1] = b;
            maxx[2] = c;
            maxx[3] = d;
            lli dp;

            for(lli i=0; i<4; i++)
            {
                for(lli j=0; j<=maxx[i]; j++)
                {
                    if(i == 0)
                     dp = j;
                    else if(i == 1)
                     dp = a + j;
                    else if(i == 2)
                     dp = a + b + j;
                    else
                     dp = a + b + c + j;

                    if(dp == 1000000)
                    {
                        //cout<<"i = "<<i<<"\n";
                        if(i == 0)
                            cout<<j<<" "<<0<<" "<<0<<" "<<0<<"\n";
                        else if(i == 1)
                            cout<<a<<" "<<j<<" "<<0<<" "<<0<<"\n";
                        else if(i == 2)
                            cout<<a<<" "<<b<<" "<<j<<" "<<0<<"\n";
                        else
                            cout<<a<<" "<<b<<" "<<c<<" "<<j<<"\n";

                        goto l;
                    }
                }
            }
        }
        l:
        t--;
    }
    return 0;
}

