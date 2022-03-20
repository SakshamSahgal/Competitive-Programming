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

void pair_printer(vector<pair<lli,lli>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

bool my_comp(pair<lli,lli>a,pair<lli,lli> b)
{
    return (a.second > b.second);
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
        lli time[n];
        lli h[n];
        for(int i=0; i<n; i++)
            cin>>time[i];

        for(int i=0; i<n; i++)
            cin>>h[i];

        vector<pair<lli,lli>> v;

        for(int i=0; i<n; i++)
            v.push_back({(time[i]-h[i]+1),time[i]});

        sort(v.begin(),v.end(),my_comp);

        //pair_printer(v);

        lli i=0;
        lli sum=0;
        while(i < v.size())
        {
            lli j = i;
            lli mini = v[i].first;
            lli maxx = v[i].second;
            while(j+1 < v.size() && v[j+1].second >= mini)
            {
                j++;
                mini = min(v[j].first,mini);
                maxx = max(v[j].second,maxx);
            }
            lli length = maxx - mini + 1;
            //cout<<"mini = "<<mini<<" maxx = "<<maxx<<" length = "<<length<<"\n";
            sum += (length*(length + 1))/2;
            i = j+1;
        }
        cout<<sum<<"\n";
        t--;
    }
    return 0;
}
