#include<bits/stdc++.h>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
// basic debugging macros
lli __i__,__j__;
lli inf = 9e18;
lli mod = 1e9+7;
#define line_printer(l) cout<<"\n"; for(__i__=0;__i__<l;__i__++){cout<<"-";}cout<<endl;
#define array_printer(a,l) cout<<#a<<": ";for(__i__=0;__i__<l;__i__++){cout<<a[__i__]<<" ";}cout<<"\n";
#define array_2d_printer(a,r,c) cout<<"\n"<<#a<<":\n";for(__i__=0;__i__<r;__i__++){for(__j__=0;__j__<c;__j__++){cout<<a[__i__][__j__]<<" ";}cout<<"\n";}
using namespace std;
typedef pair<lli,lli> pll;

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
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        k--;
        vector<vector<lli>> v(k,vector<lli>(n,0));
        lli ans = 1;
        for(int i=0;i<k;i++)
        {
            if(i == 0)
            {
                for(int j=0;j<n;j++)
                    v[i][j] = 1;
            }
            else
            {
                lli s=0;
                if(i%2 == 1)
                {
                    for(int j=n-1;j>=0;j--)
                    {
                        v[i][j] = s;
                        s = (v[i-1][j]%mod + s%mod)%mod;
                    }
                }
                else
                {
                    for(int j=0;j<n;j++)
                    {
                        v[i][j] = s;
                        s = (v[i-1][j]%mod + s%mod)%mod;
                    }
                }
            }
        }
        //Vec_2d_printer(v);

        for(int i=0;i<v.size();i++)
        {
            for(int j=0;j<v[i].size();j++)
                ans = (ans + v[i][j])%mod;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
