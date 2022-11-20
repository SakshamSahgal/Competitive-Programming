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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    string s;
    cin>>s;
    lli n = s.length();
    vector<vector<lli>> pf(26,vector<lli>(n,0));
    map<char,vector<lli>> ci;
    map<char,lli> cc;

    for(int i=n-1; i>=0; i--)
    {
        ci[s[i]].push_back(i);
        cc[s[i]]++;
        for(int j=0;j<26;j++)
            pf[j][i] = cc[ 'a' + j ];
    }

    //Vec_2d_printer(pf);
    lli ans=0;

    for(auto i:ci)
        ans = max(ans,(lli)i.second.size());

    for(char i='a';i<='z';i++)
    {
        for(char j='a';j<='z';j++)
        {
            lli th = 0;
            for(auto fc:ci[i])
            {
                if(fc != n-1)
                    th += pf[(j - 'a')][fc+1];
            }
            ans = max(ans,th);
        }
    }
    cout<<ans<<"\n";
    return 0;
}

