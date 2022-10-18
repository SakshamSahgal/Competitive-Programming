#include<iostream>
#include<cstring>
#include<vector>
#include<set>
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

//remember to use endl instead of \n for interactive problems.

int main()
{
    GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        vector<string> s(n);
        vector<lli> ans(n,0);
        map<string,lli> f;
        for(int i=0;i<n;i++)
        {
            cin>>s[i];
            f[s[i]]++;
        }

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<s[i].length();j++)
            {
                string s1 = s[i].substr(0,j+1);
                string s2 = s[i].substr(j+1);
                if(f[s1] != 0 && f[s2] != 0)
                    ans[i] = 1;
            }
        }

        for(auto i:ans)
            cout<<i;
        cout<<"\n";
        t--;
    }
    return 0;
}
