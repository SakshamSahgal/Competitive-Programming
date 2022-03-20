#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<queue>
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

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
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
        lli a[n];
        map<lli,lli> f;

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            f[a[i]]++;
        }

        lli maxx_freq = 2;
        //Map_printer(f);
        vector<pair<lli,lli>> vv; //freq,val
        for(auto i:f)
        {
            maxx_freq = max(maxx_freq,i.second);
            vv.push_back({i.second,i.first});
        }

        sort(vv.begin(),vv.end(),greater<pair<lli,lli>>());
        //cout<<"max freq = "<<maxx_freq<<"\n";
        vector<queue<lli>> v;


        queue<lli> temp;
        queue<lli> rem;

        for(auto i:vv)
        {
            if(i.first == maxx_freq)
                temp.push(i.second);
            else
            {
                int j = 0;
                while(j < i.first)
                {
                    rem.push(i.second);
                    j++;
                }
            }
        }

        for(int i=0; i<maxx_freq; i++)
            v.push_back(temp);

        int i=0;

        while(!rem.empty())
        {
            v[i++].push(rem.front());
            rem.pop();
            i = i%(maxx_freq-1);
        }

        lli b[n];
        int cur = 0;

        for(auto &&i:v)
        {
            while(!i.empty())
            {
                b[cur++] = i.front();
                i.pop();
            }
        }

        //array_printer(b,n);

        map<lli,vector<lli>> g;

        for(int i=0; i<n; i++) //O(n)
            g[b[i]].push_back(i);

        //O(n)
        lli ans = inf;
        for(auto i:g)
        {
            if(i.second.size() > 1)
            {
                lli mini_dist = inf;
                for(int j=0; j<i.second.size()-1; j++)
                    mini_dist = min(mini_dist,i.second[j+1]-i.second[j] - 1);
                ans = min(mini_dist,ans);
            }
        }

        cout<<ans<<"\n";

        t--;
    }
    return 0;
}

