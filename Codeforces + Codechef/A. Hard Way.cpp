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
        lli x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1;
        cin>>x2>>y2;
        cin>>x3>>y3;
        if( (y1 == y2) || (y1 == y3) || (y2 == y3) )
        {
            if(y1 == y2)
            {
                if(y3 < y1)
                    cout<<abs((x1-x2))<<"\n";
                else
                    cout<<0<<"\n";
            }
            else if(y1 == y3)
            {
                if(y2 < y3)
                    cout<<abs((x1-x3))<<"\n";
                else
                    cout<<0<<"\n";
            }
            else
            {
                if(y1 < y2)
                    cout<<abs((x2-x3))<<"\n";
                else
                    cout<<0<<"\n";
            }
        }
        else
            cout<<0<<"\n";
        t--;
    }
    return 0;
}

