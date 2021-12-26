#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<unordered_map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void map_printer(multimap<int,int,greater<int>> x)
{
    cout<<"\n--------------\n";
    cout<<"key = (freq) ";
    for(auto i=x.begin(); i!=x.end(); i++)
        cout<<i->first<<" ";
    cout<<"\n";
    cout<<"val = (type) ";
    for(auto i=x.begin(); i!=x.end(); i++)
        cout<<i->second<<" ";
    cout<<"\n--------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int q;
    cin>>q;
    while(q)
    {
        int n;
        cin>>n;
        int x;
        unordered_map<int,int> a; //key = type value = freq
        multimap<int,int,greater <int> > b; //key = freq value = type
        vector<pair<int,int>> p;
        for(int i=0; i<n; i++)
        {
            cin>>x;
            a[x]++;
        }

        /*
        cout<<"\n";
        for(auto i=a.begin();i!=a.end();i++)
            cout<<i->first<<" ";
        cout<<"\n";
        for(auto i=a.begin();i!=a.end();i++)
            cout<<i->second<<" ";
        cout<<"\n";*/
        for(auto i=a.begin(); i!=a.end(); i++)
        {
            b.insert({i->second,i->first});
            //b[i->second] = i->first;
        }
       // map_printer(b);

        for(auto ptr = b.begin(); ptr!=b.end(); ptr++)
            p.push_back({ptr->first,ptr->second});

        lli sum=0;
        for(auto i = p.begin(); i!=p.end(); i++)
        {
            if(i != p.begin())
            {
                auto j = i;
                j--;
                if(i->first < j->first)
                    sum+=i->first;
                else
                {
                    if(i->first > j->first)
                    {
                        i->first = j->first;
                    }

                    i->first--;
                    if(i->first > 0)
                    sum+=i->first;
                    else
                        break;
                }
            }
            else
                sum+= i->first;

            //cout<<sum<<"\n";
        }

        cout<<sum<<"\n";
        q--;
    }


    return 0;
}
