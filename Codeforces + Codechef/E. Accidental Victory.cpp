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
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        vector<pair<lli,lli>> v;

        for(int i=0; i<n; i++)
        {
            lli x;
            cin>>x;
            v.push_back({x,i+1});
        }

        if(n == 1)
        {
            cout<<1<<"\n";
            cout<<1<<"\n";
        }
        else
        {
            sort(v.begin(),v.end());
            set<lli> s;
            for(int i=0; i<n; i++)
            {
                if(i == 0)
                {
                    if(v[i+1].first == v[i].first)
                        s.insert(v[i].second);
                }
                else
                    s.insert(v[i].second);
            }

            cout<<s.size()<<"\n";

            for(auto i:s)
                cout<<i<<" ";

            cout<<"\n";
        }


        t--;
    }
    return 0;
}


