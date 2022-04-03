#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<iomanip>
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

void display(map<lli,vector<lli>> g)
{
    cout<<"\n-------------------\n";
    for(auto i:g)
    {
        cout<<i.first<<"-> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
    cout<<"\n-------------------\n";
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
        lli a[n];
        lli b[n];
        map<lli,vector<lli>> g;

        for(lli i=0; i<n; i++)
            cin>>a[i];

        for(lli i=0; i<n; i++)
            cin>>b[i];

        for(int i=0; i<n; i++)
            g[b[i]].push_back(a[i]);

        //display(g);

        multiset<lli,greater<lli>> y;
        long double ans = 0;
        long double sum = 0;
        if(g[0].size() == 0)
            cout<<0<<"\n";
        else
        {
            lli c=0;
            for(auto i:g[c])
                y.insert(i);
            while(y.size() != 0)
            {
                lli taking = *y.begin();
                //cout<<"taking = "<<taking;
                c++;
                sum += taking;
                long double z = sum/(c*1.0);
                //cout<<" my = "<<z<<"\n";
                y.erase(y.begin());
                ans = max(ans,z);
                for(auto i:g[c])
                 y.insert(i);
            }
            cout<<setprecision(20)<<ans<<"\n";
        }

        t--;
    }
    return 0;
}

