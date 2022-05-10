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
        lli a[n];
        lli oc=0;
        lli zc=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            (a[i] == 1)?oc++:zc++;
        }

        lli m=1;
        while(m<n)
        {
            if(m%2)
            {
                if( zc>=2 || (zc>=1 && oc >=1 ))
                    zc--;
                else
                    oc--;
            }
            else
            {
                if( oc>=2 || (zc>=1 && oc >=1 ))
                    oc--;
                else
                    zc--;
            }
            m++;
        }
        if(zc == 0)
            cout<<1<<"\n";
        else
            cout<<0<<"\n";
        t--;
    }
    return 0;
}
