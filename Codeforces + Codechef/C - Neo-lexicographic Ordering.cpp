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

map<char,char> mm;

bool cmp(string &a,string &b)
{
    for(int i=0; i< (min(a.length(),b.length()));i++ )
    {
        if(a[i] == b[i])
            continue;
        if(mm[a[i]] < mm[b[i]])
            return true;
        else
            return false;
    }
    return (a.size()<b.size());
}
int main()
{
    //GO_FAST

    string s;
    cin>>s;
    for(int i=0; i<26; i++)
        mm[s[i]] = i;

    lli n;
    cin>>n;
    vector<string> ans;
    for(lli i=0; i<n; i++)
    {
        string x;
        cin>>x;
        ans.push_back(x);
    }

    sort(ans.begin(),ans.end(),cmp);

    for(auto i:ans)
        cout<<i<<"\n";

    return 0;
}
