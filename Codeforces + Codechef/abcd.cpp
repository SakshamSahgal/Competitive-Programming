#include<bits/stdc++.h>
#define lli long long int
#define ld long double
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
lli mod = 1000000007;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;

//remember to use endl instead of \n for interactive problems.

bool is_palindrome(lli n)
{
    vector<lli> v;
    while(n != 0)
    {
        v.push_back((n%10));
        n/=10;
    }

    for(int i=0; i<v.size()/2; i++)
    {
        if(v[i] != v[v.size()-i-1])
            return 0;
    }
    return 1;
}

template<typename Z>
void Vec_2d_printer(vector<vector<Z>> x)
{
    cout<<"\n--------------------\n";
    for(auto i:x)
    {
        for(auto j:i)
        cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n--------------------\n";
}


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    vector<lli> a;
    for(lli i=1; i<=40000; i++)
    {
        if(is_palindrome(i))
            a.push_back(i);
    }
    //cout<<pal.size()<<"\n";

    vector<vector<int>> dp(a.size(),vector<int>(40001)); //denomination , to_make

    for(int i=0; i<a.size(); i++)
        dp[i][0] = 1;
    for(int i=0; i<=40000; i++)
        dp[0][i] = 1;

    for(int i=1; i<a.size(); i++)
    {
        for(int j=1; j<=40000;j++)
        {
            if(a[i] <= j)
                dp[i][j] = (dp[i-1][j]%mod + dp[i][j - a[i]]%mod)%mod; //can use this coin
            else
                dp[i][j] = dp[i-1][j]%mod; // cant use this coin yet
        }
    }

//Vec_2d_printer()

    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        cout<<dp[a.size()-1][n]<<"\n";
        t--;
    }
    return 0;
}

