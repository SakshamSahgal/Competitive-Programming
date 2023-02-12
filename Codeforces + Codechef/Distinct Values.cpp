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


set<lli>pairs(vector<lli> &arr)
{
    stack<lli> st;
    set<lli> pairs;

    st.push(arr[0]);

    for (lli i = 1; i < arr.size(); ++i)
    {
        while (!st.empty() && arr[i] > st.top())
        {
            pairs.insert(arr[i] - st.top());
            st.pop();
        }
        if (!st.empty())
        {
            lli mx = max(st.top(),arr[i]);
            lli mn = min(st.top(),arr[i]);
            pairs.insert(mx-mn);
        }
        st.push(arr[i]);
    }
    return pairs;
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
        lli n;
        cin>>n;
        vector<lli> a(n);
        for(int i=0;i<n;i++)
            cin>>a[i];

        set<lli> st = pairs(a);
        cout<<st.size()<<"\n";
        t--;
    }
    return 0;
}
