#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<unordered_set>
#include<map>
#include<unordered_map>
#include<algorithm>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
void set_printer(set<lli> x)
{
    cout<<"\n---------------------------\n";
    for(auto i =x.begin(); i!=x.end(); i++)
        cout<<*i<<" ";
    cout<<"\n---------------------------\n";
}

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void Display(map<lli,vector<lli>> g)
{
    cout<<"\n----------------------\n";

    for(auto i:g)
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
    //GO_FAST
    lli n;
    cin>>n;
    lli a[n+1];
    lli b[n+1];
    unordered_set<lli> hotels;
    for(int i=1; i<=n; i++)
    {
        cin>>a[i];
        if(a[i] == 1)
            hotels.insert(i);
    }


    for(int i=1; i<=n; i++)
        cin>>b[i];

    unordered_map<lli,lli> freq;
    unordered_set<lli> to_exc;
    for(int i=1; i<=n; i++)
        freq[b[i]]++;

    for(auto i:freq)
    {
        if(i.second > 1 && i.first != 0)
            to_exc.insert(i.first);
    }
    //set_printer(hotels);
    //set_printer(to_exc);

    /*
    for(int i=1; i<=n; i++)
        cout<<i<<" ";
    cout<<"\n";
    for(int i=1; i<=n; i++)
        cout<<b[i]<<" ";
     cout<<"\n";
     */
    map<lli,vector<lli>> g;
    for(auto i:hotels)
    {
        int j = i;
        g[i].push_back(j);

        while(b[j] != 0 && freq[b[j]] < 2)
        {
            j = b[j];
            g[i].push_back(j);
        }
    }
    lli maxx = INT_MIN;
    vector<lli> max_vec;
    //Display(g);
    lli maxx_hotel = 0;
    for(auto i:g)
    {
        lli sz = i.second.size();
        if(sz > maxx)
        {
            maxx = sz;
            maxx_hotel = i.first;
        }
    }
    cout<<maxx<<"\n";

      for(int i= maxx-1;i>=0;i--)
      cout<<g[maxx_hotel][i]<<" ";

    return 0;
}
