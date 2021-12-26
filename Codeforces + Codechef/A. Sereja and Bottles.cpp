#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


void Map_printer(map<int,int> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin>>n;
    int a[n],b[n];
    vector<pair<int,int>> v;
    for(int i=0; i<n; i++)
    {
        cin>>a[i]>>b[i];
        v.push_back({a[i],0});
    }

    int c = n;

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            if(i!=j)
            {
                if(b[i] == v[j].first && v[j].second == 0)
                {
                     v[j].second = 1;
                     c--;
                }
            }
        }
    }
    cout<<c<<"\n";
    return 0;
}
