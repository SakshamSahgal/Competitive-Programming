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

void Display(map<lli,vector<lli>> g)
{
    cout<<"\n----------------------\n";

    for(auto i:g)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }
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
        map<lli,vector<lli>> g;
        lli s=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            s += a[i];
            g[a[i]].push_back(i);
        }

        //Display(g);
        lli ans=0;
        //cout<<"sum = "<<s<<"\n";
        for(int i=0; i<n; i++)
        {
            lli x = a[i];
            if( (2*s)%n == 0 && (2*s)/n - x >= 0 )
            {
                lli y = ((2*s)/n) - x;
               // cout<<"for x = "<<x<<" y = "<<y<<"\n";
                if(g[y].size() != 0 && i != n-1)
                {
                    bool found=0;
                    auto ptr = lower_bound(g[y].begin(),g[y].end(),i);
                    if(ptr != g[y].end())
                    {
                        if( x != y )
                            found = 1;
                        else
                        {
                            ++ptr;
                            if(ptr != g[y].end())
                                found = 1;
                        }

                        if(found == 1)
                            ans += (g[y].end() - ptr);
                    }
                }
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
