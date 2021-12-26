#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
bool my_compare(pair <lli,lli> p1,pair<lli,lli>p2)
{
    return p1.second>p2.second;
}
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        lli n,x;
        cin>>n>>x;
        lli a,b;
        vector <pair<lli,lli>> m;
        for(lli i=0; i<n; i++)
        {
            cin>>a>>b;
            m.push_back(make_pair(a,b));
        }
        sort(m.begin(),m.end(),my_compare);

       //cout<<"\n";
        for(int i=0; i<n; i++)
        {
            if(m[i].first<=x)
            {
                cout<<m[i].second<<"\n";
                break;
            }
        }
        t--;
    }

    return 0;
}
