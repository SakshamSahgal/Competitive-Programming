#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

lli noo_in_range(lli a[],lli n,lli lr,lli hr)
{
    //cout<<"searching for "<<lr<<" "<<hr<<"\n";
    lli l=0;
    lli h=n-1;
    lli lw=-1;
    while(l<=h)
    {
        lli mid = (l+h)/2;
        if(lr <= a[mid] && a[mid] <= hr)
            lw = mid,h = mid-1;
        else
        {
            if(a[mid] < lr)
                l = mid+1;
            else
                h = mid-1;
        }
    }

    if(lw == -1)
        return 0;

    l=0;
    h=n-1;
    lli hw=-1;

    while(l<=h)
    {
        lli mid = (l+h)/2;
        if(lr <= a[mid] && a[mid] <= hr)
            hw = mid,l = mid+1;
        else
        {
            if(a[mid] < lr)
                l = mid+1;
            else
                h = mid-1;
        }
    }

    if(hw == -1)
        return 0;
    //cout<<"found = "<<hw-lw+1<<"\n";
    return hw-lw+1;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);



    lli n;
    cin>>n;
    lli a[n];
    lli noz=0;
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        noz += (a[i] == 0);
    }
    sort(a,a+n);
    lli ans=0;
    for(int i=0; i<n; i++)
    {
        if(a[i] != 0)
        {
            lli x = abs(a[i]);
            lli aa = noo_in_range(a,n,-2*x,-x);
            lli bb = noo_in_range(a,n,x,2*x);
            lli cc = noo_in_range(a,n,-x,(-(x+1)/2));
            lli dd = noo_in_range(a,n,((x+1)/2),x);
            ans +=  aa + bb + cc + dd - 3;
        }
    }
    ans += noz*(noz-1);
    cout<<ans/2<<"\n";
    return 0;
}

