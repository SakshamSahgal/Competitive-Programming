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

bool is_acc(lli a[],lli l,lli r)
{
    if(r-l+1 == 1)
        return 0;

    for(int i=l; i<r; i++)
    {
        if(a[i] >= a[i+1])
            return 0;
    }
    return 1;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    lli a[n];
    lli ans = -inf;
    for(int i=0; i<n; i++)
        cin>>a[i];

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            lli s=0;

            if(is_acc(a,i,j))
            {
                //cout<<"i  = "<<i<<"j = "<<j<<"\n";
                for(int k=i;k<=j;k++)
                    s += a[k];
                ans = max(ans,s);
            }
        }

    }

    if(ans == inf)
        cout<<-1<<"\n";
    else
        cout<<ans<<"\n";
    return 0;
}
