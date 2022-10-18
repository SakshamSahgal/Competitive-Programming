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

lli val(vector<lli> &z)
{
    lli s= 0;
    for(int i=0;i<z.size();i++)
    {
        s += z[i]*(i+1);
    }
    return s;
}

int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    while(t)
    {
        vector<lli> z = {1,2,3,4};
        vector<lli> ans;
        lli s=0;
        do{
            //cout<<val(z)<<"\n";
            ans.push_back(val(z));
            s += val(z);
        }
        while(next_permutation(z.begin(),z.end()));
        sort(ans.begin(),ans.end());
        for(auto i:ans)
            cout<<i<<"\n";
        cout<<s<<"\n";
        t--;
    }
    return 0;
}
