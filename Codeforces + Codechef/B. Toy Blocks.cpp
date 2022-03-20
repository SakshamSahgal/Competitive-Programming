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
        for(int i=0; i<n; i++)
            cin>>a[i];

        if(n == 2)
            cout<<0<<"\n";
        else
        {
            sort(a,a+n);

            lli have = a[0];
            lli req=0;

            for(int i=1; i<n-1; i++)
                req += (a[n-1]  - a[i]);

            //cout<<"have = "<<have<<" req = "<<req<<"\n";
            if(req >= have)
                cout<<(req - have)<<"\n";
            else
            {
                have -= req;
                if( have%(n-1) == 0)
                    cout<<0<<"\n";
                else
                    cout<<(n-1) - have%(n-1)<<"\n";
            }
        }

        t--;
    }
    return 0;
}
