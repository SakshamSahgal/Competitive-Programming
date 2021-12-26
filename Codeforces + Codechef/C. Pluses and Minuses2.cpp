#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<unordered_map>
#include<cmath>
#include<climits>
#define lli long long int
#define GO_FAST ios_base::sync_with_stdio(0);ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;

void Map_printer(unordered_map<lli,lli> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin();i!=x.end();i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}


int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        string s;
        cin>>s;
        lli a[s.length()];
        lli sum=0;
        unordered_map<lli,lli> m;
        for(int i=0;i<s.length();i++)
        {
            if(s[i] == '+')
                sum++;

            else
                sum--;
            a[i] = sum;
            if(m[a[i]] == 0)
            m[a[i]] = i+1;
        }
        lli ans=0;
        bool all_ava=1;
        for(int i=-1;i>=(-1*(s.length()));i--)
        {
            //cout<<i<<" "<<m[i]<<"\n";
            if(m[i] == 0)
            {
                ans += s.length();
                all_ava=0;
                break;
            }
            else
                ans += m[i];
        }

        if(all_ava == 1)
            ans += s.length();
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
