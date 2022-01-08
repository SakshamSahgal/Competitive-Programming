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


lli cost(lli c1,lli l1,lli r1,lli c2,lli l2,lli r2)
{
    if(l1 == l2 && r1 == r2)
        return (min(c1,c2));
    else if(r1 == r2)
    {
        if(l1 < l2)
            return c1;
        else
            return c2;
    }
    else if(l1 == l2)
    {
        if(r2 > r1)
            return c2;
        else
            return c1;
    }
    else
        return (c1+c2);
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
        lli x[n][3];
        lli mini_i=0;
        lli maxx_i=0;
        lli mini = INT_MAX;
        lli maxx = INT_MIN;
        map<lli,vector<pair<lli,lli>>> minss;
        map<lli,vector<pair<lli,lli>>> maxxs;
        for(int i=0; i<n; i++)
        {
            cin>>x[i][0]>>x[i][1]>>x[i][2];
            lli l,r,c;
            l = x[i][0];
            r = x[i][1];
            c = x[i][2];

            if(l <= mini)
            {
                if(l < mini)
                {
                    minss.clear();
                    mini = l;
                    minss[mini].push_back({c,i});
                }
                else
                {
                    mini = l;
                    minss[mini].push_back({c,i});
                }
            }

            if(r >= maxx)
            {
                if(r > maxx)
                {
                    maxxs.clear();
                    maxx = r;
                    maxxs[maxx].push_back({c,i});
                }
                else
                {
                    maxx = r;
                    maxxs[maxx].push_back({c,i});
                }
            }

            lli ans = INT_MAX;
            bool same_taken = 0;
            for(auto i:minss[mini])
            {
                for(auto j:maxxs[maxx])
                {
                    if(i.second == j.second)
                    {
                        if(i.first < ans)
                        {
                            same_taken = 1;
                            ans = i.first;
                            //cout<<"Best case till now -> mini && maxx index = "<<i.second<<" ans = "<<ans<<"\n";
                        }
                    }
                    else
                    {
                        if(i.first + j.first < ans)
                        {
                            same_taken = 0;
                            ans = (i.first + j.first);

                            lli l1 =  x[i.second][0];
                            lli r1 = x[i.second][1];
                            lli l2 = x[j.second][0];
                            lli r2 = x[j.second][1];
                            lli c1 = x[i.second][2];
                            lli c2 = x[j.second][2];
                            ans = min(ans,cost(c1,l1,r1,c2,l2,r2));
                            //cout<<"Best case till now -> mini index = "<<i.second<<"maxx index = "<<j.second<<" ans = "<<ans<<"\n";
                        }
                    }
                }
            }
            cout<<ans<<"\n";
        }
        t--;
    }
    return 0;
}
