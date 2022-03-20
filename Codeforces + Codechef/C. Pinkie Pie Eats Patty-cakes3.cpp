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
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void queue_printer(queue<lli> q)
{
    line_printer(20);
    while(!q.empty())
    {
        cout<<q.front()<<" ";
        q.pop();
    }
    line_printer(20);
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
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli b[n];
        map<lli,lli> f;
        for(int i=0; i<n; i++)
        {
            b[i] = -1;
            cin>>a[i];
            f[a[i]]++;
        }

        queue<lli> q;
        vector<pair<lli,lli>> v;
        for(auto i:f)
            v.push_back({i.second,i.first}); //freq,val

        sort(v.begin(),v.end(),greater<pair<lli,lli>>());

        pair_printer(v);

        for(auto i:v)
        {
            lli j=0;
            while( j < i.first )
            {
                q.push(i.second);
                j++;
            }
        }

        vector<lli> last;

        lli d = (n-1)/(f[q.front()]-1);
        cout<<"d = "<<d<<"\n";

        for(int i=0,j=0; j<f[q.front()]; i+=d,j++)
        {
            last.push_back(i);
            b[i] = 1;
        }

        lli c=0;
        queue<lli> qq;
        for(auto i:last)
        {
            qq.push(i);
            c++;
        }

        while(c < n)
        {
            vector<lli> temp;

            for(auto i:last)
            {
                if(i+1 < n && b[i+1] != 1)
                {
                    qq.push(i+1);
                    b[i+1] = 1;
                    temp.push_back(i+1);
                    c++;
                }
            }
            last = temp;
        }

        queue_printer(qq);
        while(!q.empty())
        {
            b[qq.front()] = q.front();
            qq.pop();
            q.pop();
        }

        array_printer(b,n);
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

