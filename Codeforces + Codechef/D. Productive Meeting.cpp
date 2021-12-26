#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<deque>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        set<pair<lli,lli>> s;
        for(int i=1; i<=n; i++)
        {
            lli x;
            cin>>x;
            if(x != 0)
            s.insert({x,i});
        }

        vector<pair<lli,lli>> ans;

        while( s.size() >= 2 )
        {
            auto ptr = s.end();
            ptr--;
            auto maxx = ptr;
            ptr--;
            auto sec_maxx = ptr;

            lli new_maxx_val = maxx->first - 1;
            lli new_maxx_index = maxx->second;
            lli new_sec_maxx_val = sec_maxx->first - 1;
            lli new_sec_maxx_index = sec_maxx->second;
            pair<lli,lli> nmax = {new_maxx_val,new_maxx_index};
            pair<lli,lli> nsmax = {new_sec_maxx_val,new_sec_maxx_index};
            s.erase(maxx);
            s.erase(sec_maxx);

            if(nmax.first > 0)
                s.insert(nmax);
            if(nsmax.first > 0)
                s.insert(nsmax);
            ans.push_back({new_sec_maxx_index,new_maxx_index});
        }

        cout<<ans.size()<<"\n";

        for(auto i:ans)
            cout<<i.first<<" "<<i.second<<"\n";

        t--;
    }
    return 0;
}
