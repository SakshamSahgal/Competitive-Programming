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
        lli n;
        cin>>n;
        lli a[n];
        lli b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            b[i] = 0;
        }

        lli peeche = a[0];

        for(lli i=1;i<n;i++)
        {
            for(lli j=0;j<=30;j++)
            {
                lli set_peeche = (peeche>>j)%2;
                lli set_this = (a[i]>>j)%2;
                if(set_peeche == 1 && set_this == 0)
                    b[i]+= powl(2,j);
            }
            peeche = b[i]^a[i];
        }

        for(int i=0;i<n;i++)
            cout<<b[i]<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}

