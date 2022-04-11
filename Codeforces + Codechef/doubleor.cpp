#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<queue>
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

//string dp[1001][3];
string fun(lli i,lli c,lli n,string h,string &s)
{
    if(i == n)
    {
       // cout<<"h = "<<h<<"\n";
        return h;
    }

   // if(dp[i][c] != "")
   //     return dp[i][c];

   // cout<<"{"<<i<<" , "<<c<<" }\n";

    h += s[i];

    if(c == 2)
        h = fun(i+1,1,n,h,s);
    else
    {
        h = min(fun(i+1,1,n,h,s),fun(i,2,n,h,s));
      //  dp[i][c] = h;
    }
    return h;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    int t;
    cin>>t;
    lli c=1;
    while(t)
    {
        /*
        for(int i=0;i<=1000;i++)
        {
            dp[i][0] = "";
            dp[i][1] = "";
            dp[i][2] = "";
        } */

        string s;
        cin>>s;
        lli n = s.length();
        string h;
        cout<<"Case #"<<c++<<": ";
        cout<<fun(0,1,n,h,s)<<"\n";
        //cout<<h<<"\n"
        t--;
    }
    return 0;
}

