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

int setBitNumber(int n)
{
    if (n == 0)
        return 0;

    int msb = 0;
    n = n / 2;
    while (n != 0)
    {
        n = n / 2;
        msb++;
    }

    lli z = log2((1 << msb));
    return z;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli a,b,c;
        cin>>a>>b>>c;
        bool done=0;
        for(int i=0;i<=30;i++)
        {
            lli set_a = (a>>i)%2;
            lli set_b = (b>>i)%2;
            lli set_c = (c>>i)%2;
            lli noz = 0;

            if(!set_a)
                noz++;
            if(!set_b)
                noz++;
            if(!set_c)
                noz++;

            if(noz == 3 || noz == 0)
                done = 1;
            else
            {
                if(!done)
                {
                    if(noz == 2)
                    {
                        if(set_a)
                            a += powl(2,i);
                        if(set_b)
                            b += powl(2,i);
                        if(set_c)
                            c += powl(2,i);
                    }
                    else
                    {
                        if(!set_a)
                            a += powl(2,i);
                        if(!set_b)
                            b += powl(2,i);
                        if(!set_c)
                            c += powl(2,i);
                    }
                }
                else
                {
                    cout<<"NO\n";
                    goto l;
                }
            }
        }

    if(a == b && b == c)
    cout<<"YES\n";
    else
    cout<<"NO\n";
l:
        t--;
    }
    return 0;
}
