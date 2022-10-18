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



lli calc(string &s,lli i,lli sum,map<pair<lli,lli>,lli> &dp)
{
    if(sum < 0)
        return 0;
    if(i == s.length())
    {
        if(sum == 0)
            return 1;
        else
            return 0;
    }
    if(dp.count({i,sum}))
        return dp[ {i,sum}];

    lli z=0;

    if(s[i] == '(')
        z = calc(s,i+1,sum+1,dp);
    else if(s[i] == ')')
        z = calc(s,i+1,sum-1,dp);
    else
    {
        if(sum == 0)
            z = calc(s,i+1,sum+1,dp);
        else
        {
            lli z1 = calc(s,i+1,sum+1,dp); //open
            lli z2 = calc(s,i+1,sum-1,dp); //close
            z = z1+z2;
        }
    }
    dp[ {i,sum}] = z;
    return z;
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
        string s;
        cin>>s;
        if(s.length()%2)
            cout<<"NO\n";
        else
        {
            map<pair<lli,lli>,lli> dp;
            lli val = calc(s,0,0,dp);
            //cout<<val<<"\n";
            if(val == 1)
                cout<<"YES\n";
            else
                cout<<"NO\n";
        }

        t--;
    }
    return 0;
}

