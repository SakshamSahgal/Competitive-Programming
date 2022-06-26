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
        string s;
        cin>>s;
        vector<lli> v;
        for(int i=0;i<n;i++)
            v.push_back(s[i] - '0');

        if(s[0] != '9')
        {
            for(int i=0;i<n;i++)
                cout<<(9-v[i]);
        }
        else
        {
            vector<lli> ans(n);
            for(int i=n-1;i>0;i--)
            {
                if(v[i] == 0)
                    ans[i] = 1;
                else if(v[i] == 1)
                    ans[i] = 0;
                else
                {
                    ans[i] = 11 - v[i];
                    v[i-1]++;
                }
            }
            ans[0] = 11 - v[0];
            for(auto i:ans)
                cout<<i;
        }
        cout<<"\n";
        t--;
    }
    return 0;
}
