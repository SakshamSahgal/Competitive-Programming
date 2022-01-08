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

void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}

void get_st_indexes(string &s,string &t)
{
    lli i=0;
    lli j=0;
    vector<lli> x;
    while(i < t.length())
    {
        while( j < s.length() && s[j] != s[i])
            j++;
        x.push_back(j);
        i++;
    }

    vector_printer(x);
}

int main()
{
    //GO_FAST
    lli n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector<lli> bg;

    get_st_indexes(s,t)


    return 0;
}
