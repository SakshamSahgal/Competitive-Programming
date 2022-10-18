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

//remember to use endl instead of \n for interactive problems.

lli calc(lli i,lli n,lli t[],lli x[],lli a[],lli last_id)
{
    if(i == n)
        return 0;
    else
    {
        lli last_taken=0;
        lli last_time=0;
        if(last_id != -1)
        {
            last_taken = x[last_id];
            last_time = t[last_id];
        }

        lli a1=0,a2=0;
        if(abs(last_taken - x[i]) <= t[i] - last_time)
            a1 = a[i] + calc(i+1,n,t,x,a,i);
        a2 = calc(i+1,n,t,x,a,last_id);
        return max(a1,a2);
    }
}



int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n;
    cin>>n;
    lli t[n];
    lli x[n];
    lli a[n];

    for(int i=0; i<n; i++)
        cin>>t[i]>>x[i]>>a[i];

    cout<<calc(0,n,t,x,a,-1);
    return 0;
}

