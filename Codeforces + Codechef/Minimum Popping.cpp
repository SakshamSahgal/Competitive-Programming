#include<iostream>
#include<algorithm>
#include<vector>
#include<set>
#include<map>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void map_printer(multimap<int,int> m)
{
    cout<<"\n----------------\n";
    cout<<"value  distance\n";
    for(auto i=m.begin();i!=m.end();i++)
    {
        cout<<i->first<<" "<<i->second<<"\n";
    }
    cout<<"\n----------------\n";
}

void pair_printer(vector<pair<int,int>> v)
{
    cout<<"\n------------pair------------\n";
    cout<<"value = ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" ";
    cout<<"\n";
    cout<<"distance = ";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].second<<" ";
    cout<<"\n-------------------------------\n";
}


int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n,m;
        cin>>n>>m;
        vector<pair<int,int>> a;
        int temp;
        int d=0;
        multimap<int,int> h;
        for(int i=0; i<m; i++)
        {
            cin>>temp;
            d = min(i+1,m-i);
            a.push_back(make_pair(temp,d));
            if(temp>=1 && temp<=n)
            {
                if(h.size() == 0)
                {
                   h.insert((pair <int, int> (temp,d)));
                }
                else
                {
                    auto ptr = h.find(temp);
                    if( ptr == h.end())
                        h.insert((pair <int, int> (temp,d)));
                    else
                    {
                        if( (ptr->second) > d )
                        {
                           int g = ptr->first;
                           h.erase(ptr);
                           h.insert(make_pair(g,d));
                        }
                    }
                }

            }

        }

        pair_printer(a);
        map_printer(h);
        int maxx=INT_MIN;
        for(auto i=h.begin();i!=h.end();i++)
        {
            if(i->second > maxx)
                maxx = i->second;
        }

        cout<<maxx<<"\n";
        t--;
    }

    return 0;
}
