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

lli pw;

lli toz(lli n)
{
    lli mx=-1;
    for(lli i=0; i<=21; i++)
    {
        lli sb = (n>>i)%2;
        if(sb)
            mx = i;
    }

    lli tz = -1;
    for(lli i=0; i<mx; i++)
    {
        lli z = (n>>i)%2;
        if(z == 0)
        {
            tz = powl(2,i+1) - 1;
            pw = i+1;
        }
    }
    return tz;
}

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);

        lli n;
        cin>>n;
        vector<lli> ans;
        lli c=0;
        while(toz(n) != -1)
        {
            c++;
            ans.push_back(pw);
            n = n^toz(n);
            //cout<<"n = "<<n<<"\n";
            if(toz(n) == -1)
                break;
            else
            {
                n = n+1;
                c++;
            }
        }
        cout<<c<<"\n";
        for(auto i:ans)
            cout<<i<<" ";
        cout<<"\n";

    return 0;
}

