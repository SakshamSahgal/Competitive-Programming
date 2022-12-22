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
    string s;
    cin>>s;
    lli i=0;
    lli n = s.length();
    vector<pair<char,lli>> z;
    while(i < n)
    {
        lli j=i;
        while(j+1 < n && s[j+1] == s[i])
            j++;
        z.push_back({s[i],j-i+1});
        i = j+1;
    }

    for(int i=0;i<z.size();i++)
        z[i].second = min(z[i].second,(lli)2);

    for(int i=0;i<z.size()-1;i++)
    {
        if(z[i].second == 2 && z[i+1].second == 2)
            z[i+1].second = 1;
    }

    for(auto i:z)
    {
        for(int j=0;j<i.second;j++)
            cout<<i.first;
    }

    return 0;
}

