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


int main()
{
    GO_FAST
    string s;
    cin>>s;
    map<char,char> mm;
    multimap<string,string> hh;
    char cc = 'a';
    for(int i=0; i<s.length(); i++)
    {
        mm[s[i]] = cc;
        cc++;
    }

    lli n;
    cin>>n;

    for(lli i=0; i<n; i++)
    {
        string x;
        string y;
        cin>>x;
        for(lli j=0; j<x.length(); j++)
            y += mm[x[j]];

        hh.insert({y,x});
    }

    for(auto i:hh)
        cout<<(i.second)<<"\n";
    return 0;
}
