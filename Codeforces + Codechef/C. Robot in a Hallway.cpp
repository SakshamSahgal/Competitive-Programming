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


lli m1(vector<vector<lli>> a,lli n,vector<vector<lli>> &dp_1)
{
    lli elap=0;
    for(int i=0; i<n-1; i++)
    {
        a[0][i+1]-=elap;
        if(a[0][i+1] > 0)
            elap += a[0][i+1];
        elap++;
        dp_1[0][i+1] = elap;
    }

    a[1][n-1] -= elap;
    if(a[1][n-1] > 0)
        elap+=a[1][n-1];
    elap++;
    dp_1[1][n-1] = elap;

    for(int i=n-1; i>0; i--)
    {
        a[1][i-1] -= elap;
        if(a[1][i-1] > 0)
            elap += a[1][i-1];
        elap++;
        dp_1[1][i-1] = elap;
    }
    return elap;
}

lli m2(vector<vector<lli>> a,lli n,vector<vector<lli>> dp_2)
{
    lli elap=0;
    if(a[1][0] > 0)
        elap += a[1][0];
    elap++;

    dp_2[1][0] = elap;

    for(int i=0; i<n-1; i++)
    {
        a[1][i+1] -= elap;
        if(a[1][i+1] > 0)
            elap += a[1][i+1];
        elap++;
        dp_2[1][i+1] = elap;
    }

    a[0][n-1] -= elap;
    if( a[0][n-1] > 0)
        elap += a[0][n-1];
    elap++;

    dp_2[0][n-1] = elap;

    for(int i=n-1; i>=2; i--)
    {
        a[0][i-1] -= elap;
        if(a[0][i-1] > 0)
            elap += a[0][i-1];
        elap++;
        dp_2[0][i-1] = elap;
    }
    return elap;
}

lli m3(vector<vector<lli>> a,lli n,vector<vector<lli>> dp_3)
{

    lli elap=0;
    if( a[1][0] > 0)
        elap += a[1][0];
    elap++;
    dp_3[1][0] = elap;

    for(int i=1; i<n-1; i+=2)
    {
        a[1][i] -= elap;
        if(a[1][i] > 0)
            elap += a[1][i];
        elap++;
        a[0][i] -= elap;
        if(a[0][i] > 0)
            elap += a[0][i];
        elap++;
        a[0][i+1] -= elap;
        if(a[0][i+1] > 0)
            elap += a[0][i+1];
        elap++;
        a[1][i+1] -= elap;
        if(a[1][i+1] > 0)
            elap += a[1][i+1];
        elap++;
    }
    if(n%2 == 0)
    {
        a[1][n-1] -= elap;
        if(a[1][n-1]>0)
            elap += a[1][n-1];
        elap++;

        a[0][n-1] -= elap;
        if(a[0][n-1] > 0)
            elap += a[0][n-1];
        elap++;
    }
    return elap;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<vector<lli>> a(2,vector<lli>(n));
        for(int i=0; i<2; i++)
            for(int j=0; j<n; j++)
                cin>>a[i][j];
        lli p1= m1(a,n);
        lli p2= m2(a,n);
        lli p3= m3(a,n);
        //cout<<p1<<" "<<p2<<" "<<p3<<"\n";
        lli z = min(p1,min(p2,p3));
        cout<<z<<"\n";
        t--;
    }
    return 0;
}
