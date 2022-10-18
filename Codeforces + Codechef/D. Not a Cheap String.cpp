#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#include<queue>
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
        string s;
        cin>>s;
        lli p;
        cin>>p;
        lli cost=0;
        priority_queue<pair<char,lli>> pq;
        for(int i=0;i<s.length();i++)
        {
             pq.push({s[i],i});
             cost += ((s[i] - 'a') + 1);
        }


        while(pq.size() && cost > p)
        {
            char z = (pq.top().first);
            cost -= ( z - 'a' + 1);
            pq.pop();
        }

        set<pair<lli,char>> ss;
        while(!pq.empty())
        {
            ss.insert({pq.top().second,pq.top().first});
            pq.pop();
        }

        for(auto i:ss)
            cout<<i.second;
        cout<<"\n";
        t--;
    }
    return 0;
}
