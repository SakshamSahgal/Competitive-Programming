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
    lli n;
    cin>>n;
    lli a[n];
    lli ans=n-1;
    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int pl=0;pl<=n;pl++)
    {
        lli sl = n - pl;
        map<lli,lli> f;
        lli del=0;
        lli delp=0;
        lli dels=0;
        for(int j=0;j<pl;j++)
        {
            if(f[a[j]] == 0)
            {
                delp++;
                f[a[j]]++;
            }
            else
                break;
        }

        for(int j=n-1,k=0;k<sl;k++,j--)
        {
            if(f[a[j]] == 0)
            {
                dels++;
                f[a[j]]++;
            }
            else
                break;
        }
        //cout<<" pl = "<<pl<<" sl = "<<sl<<" taken = "<<"{ "<<delp<<" , "<<dels<<" } \n";
        del = delp + dels;
        ans = min(ans,n-del);
    }
    cout<<ans<<"\n";
    return 0;
}

