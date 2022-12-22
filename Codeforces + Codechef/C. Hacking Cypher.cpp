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

lli fast_Power(lli a,lli b,lli n)
{
    lli res = 1;
    while(b>0)
    {
        if((b&1) != 0) //b is odd
            res = ((res%n)*(a%n))%n;

        a = ((a%n)*(a%n))%n;
        b = b>>1; //b = b/2
    }
    return res;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    string s;
    cin>>s;
    lli a,b;
    cin>>a>>b;
    lli n = s.length();
    lli prefix[n];
    lli suffix[n];
    for(lli i=0; i<n; i++)
    {
        prefix[i] = (i == 0) ? (s[i] - '0') : prefix[i-1]*10 + (s[i] - '0');
        prefix[i] = prefix[i]%a;
    }

    for(lli i=n-1; i>=0; i--)
    {
        lli pw = fast_Power(10,n - 1 - i,b);
        suffix[i] = (i == n-1) ? pw*(s[i] - '0') : pw*(s[i] - '0') + suffix[i+1];
        suffix[i] = suffix[i]%b;
    }

    //array_printer(prefix,n);
    //array_printer(suffix,n);

    for(lli i=0;i<n-1;i++)
    {
        if(prefix[i] == 0 && suffix[i+1] == 0 && s[i+1] != '0')
        {
            cout<<"YES\n";
            string aa = s.substr(0,i+1);
            string bb = s.substr(i+1,n - i - 1);
            cout<<aa<<"\n"<<bb<<"\n";
            goto l;
        }
    }
    cout<<"NO\n";
    l:

    return 0;
}

