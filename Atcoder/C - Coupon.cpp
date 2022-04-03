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

    lli n,k,x;
    cin>>n>>k>>x;
    lli a[n];
    lli sum=0;

    for(lli i=0; i<n; i++)
    {
        cin>>a[i];
        sum += a[i];
    }

    sort(a,a+n);
    //array_printer(a,n);
    for(lli i=n-1; i>=0; i--)
    {
        lli mxc = a[i]/x;
        //cout<<"mxc = "<<mxc<<"\n";
        if(mxc != 0)
        {
            if(mxc <= k)
            {
                k -= mxc;
                sum -= mxc*x;
                a[i] -= mxc*x;
            }
            else
            {
                sum -= k*x;
                k = 0;
                goto l;
            }
        }
    }
    //array_printer(a,n);
    sort(a,a+n);
    for(lli i=n-1; i>=0; i--)
    {
        if(k>0)
        {
            sum -= a[i];
            a[i] = 0;
            k--;
        }
        else
            break;
    }
    //array_printer(a,n);

l:
    cout<<sum<<"\n";

    return 0;
}

