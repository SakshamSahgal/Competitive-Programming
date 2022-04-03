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

lli val(vector<lli> order,lli f[],lli p[],lli n)
{
    bool done[n] = {0};
    lli ans=0;
    for(int i=0; i<order.size(); i++)
    {
        lli val = 0;
        //cout<<" at i = "<<order[i]<<" \n";
        if(done[order[i]] == 0)
        {
            val = max(f[order[i]],val);
            //cout<<" taking =  "<<val<<" \n";
            done[order[i]] = 1;
        }
        lli cur = p[order[i]];
        while(cur != -1)
        {
            if(done[cur] == 0)
            {
                val = max(val,f[cur]);
                //cout<<" taking =  "<<val<<" \n";
                done[cur] = 1;
            }
            cur = p[cur];
        }
        //cout<<"Best ans = "<<val<<"\n";
        ans += val;
    }
    return ans;
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}
int main()
{
    //GO_FAST
    //freopen("input.txt", "r", stdin);
    //freopen("myout.txt", "w", stdout);
    int t;
    cin>>t;
    lli ct = 1;
    while(t)
    {
        lli n;
        cin>>n;
        lli f[n];
        lli p[n];
        set<lli> init;
        for(lli i=0; i<n; i++)
        {
            cin>>f[i];
            init.insert(i);
        }

        for(lli i=0; i<n; i++)
        {
            cin>>p[i];
            p[i]--;
            if(p[i] != -1)
            {
                auto ptr = init.find(p[i]);
                if(ptr != init.end())
                    init.erase(ptr);
            }

        }

        vector<lli> order;
        cout<<"Case #"<<(ct++)<<": ";
        for(auto i:init)
            order.push_back(i);

        lli ans = -inf;

        sort(order.begin(),order.end());
        do
        {
            //vector_printer(order);
            lli best = val(order,f,p,n);
            //cout<<"best ans = "<<best<<"\n";
            ans = max(ans,best);
        }
        while(next_permutation(order.begin(),order.end()));
        cout<<ans<<"\n";

        t--;
    }
    return 0;
}

