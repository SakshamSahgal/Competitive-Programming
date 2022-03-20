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
    lli n,k;
    cin>>n>>k;
    lli a[n];
    for(int i=0; i<n; i++)
        cin>>a[i];

    sort(a,a+n);
    //array_printer(a,n);
    map<lli,lli> ind;

    for(int i=0; i<n; i++)
        ind[a[i]] = i+1;

    bool rem[n];

    memset(rem,1,n*sizeof(bool));

    //array_printer(rem,n);

    for(int i=0; i<n; i++)
    {
        if(rem[i] == 1 && k != 1)
        {
            if( ind[ k*a[i] ] != 0)
                rem[ind[(k*a[i])] - 1] = 0;
        }
    }

    lli c=0;

    //array_printer(rem,n);

    for(int i=0;i<n;i++)
        if(rem[i])
            c++;

    cout<<c<<"\n";
    return 0;
}

