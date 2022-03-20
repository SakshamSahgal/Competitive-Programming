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
lli inf = 9e18;


void Map_printer(map<lli,pair<lli,lli>> x)
{
    cout<<"\n----------------------\n";
    for(auto i:x)
        cout<<i.first<<" ("<<i.second.first<<" "<<i.second.second<<")"<<"\n";
    cout<<"\n----------------------\n";
}

void rem_for_free(map<lli,pair<lli,lli>> &m)
{
    for(auto &&i:m) //equal walo ko kaata with 0 cost
    {
        if(i.second.first != 0 && i.second.second != 0)
        {
            if(i.second.second >= i.second.first)
            {
                i.second.second = i.second.second - i.second.first;
                i.second.first = 0;
            }
            else
            {
                i.second.first = i.second.first - i.second.second;
                i.second.second = 0;
            }
        }
    }
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,l,r;
        cin>>n>>l>>r;
        lli c[n];
        map<lli,pair<lli,lli>> m;
        for(int i=0; i<n; i++)
        {
            cin>>c[i];
            if(i < l)
                m[c[i]].first++;
            else
                m[c[i]].second++;
        }

        Map_printer(m);
        rem_for_free(m);
        Map_printer();



        t--;
    }
    return 0;
}
