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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
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
        lli n,x;
        cin>>n>>x;
        string s;
        cin>>s;
        lli c=1;
        vector<lli> range(n,0);
        range[0] = c;
        for(int i=1; i<n; i++)
        {
            if(s[i-1] == s[i])
                range[i] = c;
            else
                range[i] = ++c;
        }
        map<lli,lli> f;
        //vector_printer(range);
        for(int i=0; i<n; i++)
            f[range[i]]++;

        lli ans=0;

        for(auto i:f)
        {
            if(s[0] == '1' && i.first%2 == 0)
                ans += i.second/x;
            else if(s[0] == '0' && i.first%2 == 1)
                ans += i.second/x;
        }

        lli maxx_ans=ans;
        for(int i=0; i<n; i++)
        {
            lli noz=0;
            lli this_ans = ans;
            if(s[i] == '1')
            {
                if(i-1>=0 && s[i-1] == '0')
                {
                    noz += f[range[i-1]];
                    this_ans -= f[range[i-1]]/x;
                }
                if(i+1<n && s[i+1] == '0')
                {
                    noz += f[range[i+1]];
                    this_ans -= f[range[i+1]]/x;
                }
                noz+=1;
                this_ans += noz/x;
                maxx_ans = max(this_ans,maxx_ans);
            }
        }
        cout<<maxx_ans<<"\n";
        t--;
    }
    return 0;
}
