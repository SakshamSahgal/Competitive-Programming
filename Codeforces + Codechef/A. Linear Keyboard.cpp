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
        string s1,s2;
        cin>>s1>>s2;
        map<char,lli> pos;
        for(int i=0;i<s1.length();i++)
            pos[s1[i]] = i+1;
        lli ans=0;
        for(int i=0;i<s2.length()-1;i++)
            ans += abs(pos[s2[i]] - pos[s2[i+1]]);
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
