#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
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
    int n,m;
    cin>>n>>m;
    map<string,pair<string,int>> mapper;

    for(int i=0; i<m; i++)
    {
        string s1;
        string s2;
        cin>>s1>>s2;
        mapper.insert({s1,{s2,s2.length()}});
        //cout<<"\n s1 = "<<s1<<"\n s2 = "<<s2<<"\n";
    }

    for(int i=0; i<n; i++)
    {
        string s;
        cin>>s;
        pair<string,int> p = mapper[s];
        if( (p.second) < s.length() )
            cout<<p.first<<" ";
        else
            cout<<s<<" ";
    }
    return 0;
}
