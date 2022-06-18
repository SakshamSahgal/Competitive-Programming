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

    lli x1,y1;
    lli x2,y2;
    cin>>x1>>y1;
    cin>>x2>>y2;

    lli a = (y1-y2);
    lli b = (x2-x1);
    lli c = -a*x1 - b*y1;

    lli gcd = __gcd(__gcd(abs(a),abs(b)),abs(c));

    a /= gcd;
    b /= gcd;
    c /= gcd;

  //  cout<<"a = "<<a<<" b =  "<<b<<" c = "<<c<<"\n";
    lli n;
    cin>>n;
    lli ans=0;
    for(int i=0; i<n; i++)
    {
        lli ad,bd,cd;
        cin>>ad>>bd>>cd;

        lli gcdd = __gcd(__gcd(abs(ad),abs(bd)),abs(cd));
        ad /= gcdd;
        bd /= gcdd;
        cd /= gcdd;

        //cout<<"a' = "<<ad<<" b' = "<<bd<<" c' = "<<cd<<"\n";
        if( a*bd != b*ad)
        {
            double xd = ((b*cd - bd*c)*1.0)/(a*bd - ad*b);
            double yd = ((ad*c - a*cd)*1.0)/(a*bd - ad*b);
           // cout<<"point of intersection = "<<xd<<" , "<<yd<<"\n";
            if( ( min(x1,x2) <= xd && xd <= max(x2,x1) ) && ( min(y1,y2) <= yd && yd <= max(y2,y1) ))
            {
                ans++;
                //cout<<"yes\n";
            }
        }
    }
    cout<<ans<<"\n";

    return 0;
}
