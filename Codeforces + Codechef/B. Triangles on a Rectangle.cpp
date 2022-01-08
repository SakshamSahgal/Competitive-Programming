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
using namespace std;

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli w,h;
        cin>>w>>h;
        set<lli> l1;
        set<lli> l2;
        set<lli> l3;
        set<lli> l4;

        lli k;
        cin>>k;
        for(int i=0;i<k;i++)
        {
            lli x;
            cin>>x;
            l1.insert(x);
        }
        cin>>k;
        for(int i=0;i<k;i++)
        {
            lli x;
            cin>>x;
            l2.insert(x);
        }
        cin>>k;
        for(int i=0;i<k;i++)
        {
            lli x;
            cin>>x;
            l3.insert(x);
        }
        cin>>k;
        for(int i=0;i<k;i++)
        {
            lli x;
            cin>>x;
            l4.insert(x);
        }

        lli d1 = (*l1.rbegin()) - (*l1.begin());
        lli d2 = (*l2.rbegin()) - (*l2.begin());
        lli d3 = (*l3.rbegin()) - (*l3.begin());
        lli d4 = (*l4.rbegin()) - (*l4.begin());
        lli a1 = max(d1,d2)*h;
        lli a2 = max(d3,d4)*w;
        cout<<max(a1,a2)<<"\n";

        t--;
    }
    return 0;
}
