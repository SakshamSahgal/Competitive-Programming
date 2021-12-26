#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

void Map_printer(multimap<int,pair<int,int>> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<(i->second).first<<" "<<(i->second).second<<"\n";
    cout<<"\n----------------------\n";
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
        int n;
        cin>>n;
        multimap<int,pair<int,int>> m;
        int sx=0;
        int sy=0;
        for(int i=0; i<n; i++)
        {
            int x,y;
            cin>>x>>y;
            int d = x*x + y*y;
            m.insert({d,{x,y}});
        }

        //Map_printer(m);

        auto this_one = m.begin();
        this_one++;

        auto prev_one = m.begin();
        bool fail=0;
        for(int j=1; j<n; j++)
        {
            pair<int,int> p1 = prev_one->second;
            pair<int,int> p2 = this_one->second;

            if(!(p2.second >= p1.second && p2.first >= p1.first))
            {
                cout<<"NO";
                fail = 1;
                break;
            }

            this_one++;
            prev_one++;
        }

        if(fail == 0)
        {
            cout<<"YES\n";
            for(auto i=m.begin(); i!=m.end(); i++)
            {
                pair<int,int> p = i->second;
                int x = p.first;
                int y = p.second;
                for(int i=1; i<=(x-sx); i++)
                    cout<<"R";
                for(int i=1; i<=(y-sy); i++)
                    cout<<"U";
                sx = x;
                sy = y;
            }
        }

        cout<<"\n";
        t--;
    }

    return 0;
}

