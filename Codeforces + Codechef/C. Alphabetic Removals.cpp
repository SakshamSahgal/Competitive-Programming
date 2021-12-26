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
void pair_printer(vector<pair<char,int>> v)
{
    cout<<"\n------------pair------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i].first<<" "<<v[i].second<<"\n";
    cout<<"\n-------------------------------\n";
}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int n,k;
    vector<pair<char,int>> v;
    cin>>n>>k;
    string s;
    cin>>s;

    for(int i=0; i<s.length(); i++)
        v.push_back({s[i],i});

    sort(v.begin(),v.end());

    //pair_printer(v);

    for(int i=0; i<k; i++)
        s[v[i].second] = '-';
    for(int i=0; i<s.length(); i++)
    {
        if(s[i] != '-')
            cout<<s[i];
    }

    return 0;
}

