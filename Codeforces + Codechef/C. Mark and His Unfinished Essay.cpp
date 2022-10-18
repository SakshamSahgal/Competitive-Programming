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

lli id(vector<pair<lli,lli>> &x0,vector<pair<lli,lli>> &x1,lli s)
{
    lli l = 0;
    lli h = x0.size()-1;
    while(l<=h)
    {
        lli mid = (l+h)/2;
        if( x1[mid].first <= s && s <= x1[mid].second)
                return (s - x1[mid].first + x0[mid].first);
        else if(s < x1[mid].first)
            h = mid-1;
        else
            l = mid+1;
    }
}

void pair_printer(vector<pair<lli,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
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
        lli n,c,q;
        cin>>n>>c>>q;
        lli on = n;
        string temp;
        cin>>temp;
        string s = "0";
        s += temp;
        vector<pair<lli,lli>> sted;
        vector<pair<lli,lli>> sted2;
        sted.push_back({1,n});
        sted2.push_back({1,n});
        //pair_printer(sted);
        //pair_printer(sted2);
        while(c--)
        {
            lli l,r;
            cin>>l>>r;
            lli len = r-l+1;
            sted2.push_back({n+1,n+len});
            sted.push_back({l,r});
            n += len;
        }

        //pair_printer(sted);
        //pair_printer(sted2);

        while(q--)
        {
            lli x;
            cin>>x;
            lli z = id(sted,sted2,x);
            while( z > on )
                z = id(sted,sted2,z);
            cout<<s[z]<<"\n";
        }
        t--;
    }
    return 0;
}
