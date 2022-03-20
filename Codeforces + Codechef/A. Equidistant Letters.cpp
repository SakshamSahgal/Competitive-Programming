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
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        map<char,lli> f;
        for(int i=0;i<s.length();i++)
            f[s[i]]++;

        for(auto i:f)
        {
            if(i.second == 2)
                cout<<i.first<<i.first;
        }

        for(auto i:f)
        {
            if(i.second == 1)
                cout<<i.first;
        }
        cout<<"\n";
        t--;
    }
    return 0;
}
