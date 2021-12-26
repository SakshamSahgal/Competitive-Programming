#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<pair<lli,lli>> v; //first ->element //second index
        lli prefix[n];

        for(int i=1;i<=n;i++)
        {
            lli x;
            cin>>x;
            v.push_back({x,i});
        }

        sort(v.begin(),v.end());
        lli sum=0;
        for(int i=0;i<v.size();i++)
        {
            sum += v[i].first;
            prefix[i] = sum;
        }
        set<lli> s;
        for(int i=n-1;i>=0;i--)
        {
            if(i == n-1)
                s.insert(v[i].second);
            else
            {
                if(prefix[i] >= v[i+1].first)
                    s.insert(v[i].second);
                else
                    break;
            }
        }
        cout<<s.size()<<"\n";
        for(auto i:s)
            cout<<i<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}


