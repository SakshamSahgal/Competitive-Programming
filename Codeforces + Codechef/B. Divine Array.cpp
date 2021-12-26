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

void print_it(map<lli,vector<lli>> m,map<lli,map<lli,lli>> freq)
{
    cout<<"\n-----------------------\n";
    for(auto i:m)
    {
        cout<<i.first<<" -> ";
        for(auto j:i.second)
            cout<<j<<" ";
        cout<<"\n";
    }

    for(auto i:freq)
    {
        cout<<i.first<<" -> \n";
        for(auto j:i.second)
            cout<<j.first<<" "<<j.second<<"\n";
    }
    cout<<"\n-----------------------\n";
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
        map<lli,vector<lli>> m;
        map<lli,map<lli,lli>> freq;
        lli step=0;

        for(int i=0; i<n; i++)
            cin>>a[i];


        for(step = 0; step<=n; step++)
        {
            map<lli,lli> ff;

            if(step == 0)
            {
                for(int i=0; i<n; i++)
                {
                    ff[a[i]]++;
                    m[step].push_back(a[i]);
                }
                freq[step] = ff;
            }
            else
            {
                map<lli,lli> last_freq = freq[step-1];
                for(int i=0; i<n; i++)
                {
                    lli na = last_freq[a[i]];
                    a[i] = na;
                    m[step].push_back(na);
                    ff[na]++;
                }

                freq[step] = ff;
            }
        }

        //print_it(m,freq);

        lli q;
        cin>>q;

        for(int i=0;i<q;i++)
        {
            lli x,k;
            cin>>x>>k;
            if(k<=n)
                cout<<m[k][x-1]<<"\n";
            else
                cout<<m[n][x-1]<<"\n";
        }

        t--;
    }
    return 0;
}
