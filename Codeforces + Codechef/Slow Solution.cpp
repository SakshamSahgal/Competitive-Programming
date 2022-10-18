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
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n,mxn,mxs;
        cin>>n>>mxn>>mxs;
        lli ans = -inf;
        for(lli i=1;i<=n;i++)
        {
            lli z;
            if(i*mxn <= mxs)
                z = i*mxn*mxn;
            else
            {
                lli can = ((mxs-i)/(mxn-1));
                lli rem = i - can;
                lli rems = (mxs-i)%(mxn-1) - rem + 1;
                z = (can*mxn*mxn) + (rem-1) + (rems+1)*(rems+1);
                //cout<<"i = "<<i<<" adding "<<can<<"x"<<mxn<<" "<<(rem-1)<<" 1 "<<"and "<<rems<<"\n";
            }
            ans = max(ans,z);
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}

