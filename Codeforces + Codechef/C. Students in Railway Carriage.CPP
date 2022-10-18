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


int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

    lli n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    lli i=0;
    vector<lli> anss;
    while(i < n)
    {
        //cout<<"i = "<<i<<"\n";
        if(s[i] == '.')
        {
            lli j = i;
            while(j+1 < n && s[j+1] == '.')
                j++;
            anss.push_back(j-i+1);
            i = j+1;
        }
        else
            i++;
    }
    lli ans=0;
    for(auto i:anss)
    {
        //cout<<i<<" ";
        lli mx = max(i/2,i - i/2);
        lli mn = min(i/2,i - i/2);
        if(a > b)
        {
            ans += min(a,mx);
            ans += min(b,mn);
            a -= min(a,mx);
            b -= min(b,mn);
        }
        else
        {
            ans += min(b,mx);
            ans += min(a,mn);
            b -= min(b,mx);
            a -= min(a,mn);
        }
    }

    cout<<ans<<"\n";

    return 0;
}

