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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void Map_printer(map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
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
        lli sum=0;
        map<lli,lli> f;
        for(int i=0; i<n; i++)
        {
            lli a;
            cin>>a;
            f[a]++;
        }

        map<lli,lli> ff;
        vector<lli> x;

        for(auto i:f)
            ff[i.second]++;

        for(auto i:ff)
            x.push_back(i.first);

        if(x.size() == 1)
            cout<<0<<"\n";
        else
        {
            vector<lli> pre_v(x.size());
            vector<lli> post_v(x.size());
            vector<lli> pre_pos(x.size());
            vector<lli> post_pos(x.size());

          //  Map_printer(ff);

            lli pre_sum=0;
            lli post_sum=0;
            lli pre_pos_sum = 0;
            lli post_pos_sum = 0;

            for(lli i=0,j=x.size()-1; i<x.size(); i++,j--)
            {
                pre_pos_sum += ff[x[i]];
                post_pos_sum += ff[x[j]];
                pre_sum += x[i]*ff[x[i]];
                post_sum += x[j]*ff[x[j]];
                pre_v[i] = pre_sum;
                post_v[j] = post_sum;
                pre_pos[i] = pre_pos_sum;
                post_pos[j] = post_pos_sum;
            }


           // vector_printer(x);
           // vector_printer(pre_v);
           // vector_printer(post_v);
           // vector_printer(pre_pos);
           // vector_printer(post_pos);
            lli ans = INT_MAX;
            for(int i=0; i<x.size(); i++)
            {
                lli moves=0;
                if(i == 0)
                    moves = post_v[i+1] - x[i]*post_pos[i+1];
                else if(i == x.size()-1)
                    moves = pre_v[i-1];
                else
                    moves = pre_v[i-1] + post_v[i+1] - x[i]*post_pos[i+1];
                //cout<<"For freq = "<<x[i]<<" moves req = "<<moves<<"\n";
                ans = min(ans,moves);
            }
            cout<<ans<<"\n";
        }

        t--;
    }
    return 0;
}
