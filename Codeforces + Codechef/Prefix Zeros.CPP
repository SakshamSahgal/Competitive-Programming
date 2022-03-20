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

bool is_possible(lli x,string a,lli n,lli k)
{
    lli req=0;

    for(int i=x; i>=0; i--)
    {
        lli no = (a[i]-48);
        //cout<<"adding = "<<(10 - (((no + req)%10)))%10<<"\n";
        req += (10 - (((no + req)%10)))%10;
    }
    //cout<<"req = "<<req<<"\n";
   if(req <= k)
    return 1;
   else
    return 0;
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        string s;
        cin>>s;

        //cout<<is_possible(3,s,n,k)<<"\n";
        lli l=0;
        lli h=n-1;
        lli ans=0;

        while(l<=h)
        {
            lli mid = (l+h)/2;
            //cout<<"trying "<<mid<<"\n";
            if(is_possible(mid,s,n,k))
            {
                //cout<<"possible\n";
                ans = mid+1;
                l = mid+1;
            }
            else
            {
               //cout<<"Not possible\n";
                h = mid-1;
            }

        }

        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

