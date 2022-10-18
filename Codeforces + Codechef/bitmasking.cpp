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

class Bitmask
{
public:
    lli mask=0;
    lli max_bit=-1; //max set bit

    Bitmask(lli n)
    {
        max_bit = n-1;
    }

    bool is_set(lli x)
    {
        return(((mask>>x)&(lli)1));
    }


    void set_bit(lli x) //zero based
    {
        if( !is_set(x) ) //x bit is not already set
            mask = ((mask)^(((lli)1)<<x));
    }

    void unset_bit(lli x)//zero based
    {
        if( is_set(x) ) //if xth bit is set
            mask = (mask^((lli)1<<x));
    }

    string display()
    {
        string s;
        for(lli i=0; i<=max_bit; i++)
        {
            if( is_set(i) )
                s += '1';
            else
                s += '0';
        }
        reverse(s.begin(),s.end());
        return s;
    }
};

vector<vector<lli>> dp(20,vector<lli>(1048576,-1)); // (n) x (2^n - 1)
vector<vector<lli>> val(100,vector<lli>(100,0));

lli calc_dp(lli i,lli j,lli n,Bitmask b)
{

    cout<<"{"<<i<<" , "<<b.display()<<"} j = "<<j<<"\n";
    if(i != -1 && dp[i][b.mask] != -1)
    {
        cout<<"got DP\n";
        return val[i][j] + dp[i][b.mask];
    }

    if(i == n-1)
        return val[i][j];

    lli mini = inf;

    for(lli k=0; k<n; k++)
    {
        if(!b.is_set(k))
        {
            b.set_bit(k);
            mini = min(mini,calc_dp(i+1,k,n,b));
            b.unset_bit(k);
        }
    }

    if(i == -1)
        return mini;
    else
    {
        dp[i][b.mask] = mini;
        return val[i][j]+dp[i][b.mask];
    }

}


int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    val = {{9,2,7,8},{6,4,3,7},{5,8,1,8},{7,6,9,4}};
    Bitmask b(4);
    cout<<calc_dp(-1,-1,4,b);
    return 0;
}

