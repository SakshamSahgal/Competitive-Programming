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

map<lli,vector<lli>> m;
void Display()
{
    cout<<"\n----------------------\n";

    for(auto i:m)
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

    for(int o=1; o<=t; o++)
    {
        lli d,n,k;

        cin>>d>>n>>k;

        for(lli i=1; i<=n; i++)
        {
            lli h,st,ed;
            cin>>h>>st>>ed;

            for(int j=st; j<=ed; j++)
                m[j].push_back(h);
        }

        lli maxx = 0;
        for(int i=1; i<=d; i++)
        {
            if(m[i].size() > 0)
            {
                sort(m[i].begin(),m[i].end(),greater<int>());
                lli sum=0;
                lli c=0;
                for(auto j = m[i].begin(); j!=m[i].end(); j++)
                {
                    sum += *j;
                    c++;
                    if(c >= k)
                        break;
                }

                //cout<<"sum = "<<sum<<"\n";
                maxx = max(maxx,sum);
            }
        }
        //Display();
        m.clear();
        cout<<"Case #"<<o<<": "<<maxx<<"\n";
    }


    return 0;
}
