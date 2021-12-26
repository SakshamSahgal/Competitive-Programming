#include<iostream>
#include<algorithm>
#include<vector>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void pair_printer(vector<pair<int,int>> v)
{
    cout<<"\n------------pair------------\n";
    cout<<"starting =";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" ";
    cout<<"\n";
    cout<<"ending =";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].second<<" ";
    cout<<"\n-------------------------------\n";
}

bool my_compare(pair <int,int> a,pair<int,int> b)
{
    return (a.first<b.first);
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    lli t;
    cin>>t;
    while(t)
    {
        lli n,k,f;
        lli max_ending = INT_MIN;
        cin>>n>>k>>f;
        vector<pair<int,int>> p;
        int s,e;
        for(int i=0; i<n; i++)
        {
            cin>>s>>e;
            if(max_ending < e)
                max_ending = e;

            p.push_back(make_pair(s,e));
        }
        sort(p.begin(),p.end(),my_compare);

        for(int i=0; i<p.size(); i++)
        {
            if( i != 0 && p[i].second < p[i-1].second )
            {
                p[i].second = p[i-1].second;
            }
        }

        //pair_printer(p);
        lli sum=0;
        sum+=p[0].first;
        for(int i=0; i<p.size()-1; i++)
        {
            if( (p[i+1].first - p[i].second) > 0)
            {
                sum+=(p[i+1].first - p[i].second);
            }
        }
        sum += f - max_ending;
      //  cout<<"free time = "<<sum<<"\n";

        if(sum >= k)
            cout<<"YES\n";
        else
            cout<<"NO\n";

        t--;
    }

    return 0;
}

