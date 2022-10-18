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
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    lli n,k;
    cin>>n>>k;
    lli p[n+1];
    set<lli> st;
    map<lli,vector<lli>> sz;
    map<lli,lli> st_no;
    set<lli> ava;
    vector<lli> ans(n+1,-1);
    for(int i=1; i<=n; i++)
    {
        cin>>p[i];
        ava.insert(i);
    }


    for(int i=1; i<=n; i++)
    {
        auto ptr = st.lower_bound(p[i]);
        if(ptr == st.end())
        {
            sz[(*ava.begin())].push_back(p[i]);
            st_no[p[i]] = (*ava.begin());
            ava.erase(ava.begin());
            cout<<p[i]<<" going to "<<st_no[p[i]]<<"\n";
        }
        else
        {
            sz[st_no[(*ptr)]].push_back(p[i]);
            st_no[p[i]] = st_no[(*ptr)];
            cout<<p[i]<<" going to "<<st_no[p[i]]<<"\n";
        }
        st.insert(p[i]);
        if(sz[st_no[p[i]]].size() == k)
        {
            cout<<st_no[p[i]]<<" full "<<"\n";
            for(auto j:sz[st_no[p[i]]])
            {
                auto ptr = st.find(j);
                if(ptr != st.end())
                {
                    ans[j] = i;
                    st.erase(ptr);
                }
            }
            sz[st_no[p[i]]].clear();
            ava.insert(st_no[p[i]]);
        }
    }

    for(int i=1;i<=n;i++)
        cout<<ans[i]<<" ";
    return 0;
}
