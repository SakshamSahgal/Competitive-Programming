#include<bits/stdc++.h>
#define lli long long int
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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];

        for(int i=0;i<n;i++)
            cin>>a[i];

        lli a=0;
        lli b=0;
        lli c=0;
        lli s = a[0];
        for(lli i=1;i<n;i++)
        {
           if(!(i&(i-1)))
           {
             lli set_bits = (s + 3*i - a[i])/(2*i);
             if(set_bits >= 1)
                a += i;
             if(set_bits >= 2)
                b += i;
             if (set_bits == 3)
                c += i;
           }
           else
           {

           }
        }

        t--;
    }
    return 0;
}

