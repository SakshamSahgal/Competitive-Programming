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


/*
void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
} */

vector<lli> get_st_indexes(string &s,string &t)
{
    lli j=0;
    vector<lli> x;
    for(int i=0;i<t.length();i++)
    {
        while( j < s.length() && s[j] != t[i])
            j++;
        x.push_back(j);
        j++;
    }
  //  vector_printer(x);
    return x;
}

vector<lli> get_ed_index(string &s,string &t)
{
    vector<lli> x;
    lli j = s.length()-1;

    for(lli i = t.length()-1;i>=0;i--)
    {
        while(j >=0 && s[j] != t[i])
            j--;
        x.push_back(j);
        j--;
    }

    vector<lli> y;

    for(int i=x.size()-1;i>=0;i--)
        y.push_back(x[i]);

   // vector_printer(y);
    return y;
}

int main()
{
    GO_FAST
    lli n,m;
    cin>>n>>m;
    string s,t;
    cin>>s>>t;
    vector<lli> bg;

    vector<lli> a = get_st_indexes(s,t);
    vector<lli> b = get_ed_index(s,t);

    lli maxx = 0;

    for(int i=0;i<t.length()-1;i++)
        maxx = max( maxx ,( b[i+1] - a[i] ) );
    cout<<maxx<<"\n";
    return 0;
}
