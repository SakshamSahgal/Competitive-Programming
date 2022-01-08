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
const int mod=1e9+7;

vector<pair<char,lli>> consecutive_freq(string a)
{
    vector<pair<char,lli>> x;
    lli i=0;
    while(i < a.length())
    {
        lli c=1;
        lli j=i+1;
        while( j < a.length() && a[j] == a[i])
        {
            j++;
            c++;
        }
        x.push_back({a[i],c});
        i = j;
    }
    return x;
}

void pair_printer(vector<pair<char,lli>> v)
{
cout<<"\n------------pair------------\n";
for(int i=0;i<v.size();i++)
    cout<<v[i].first<<" "<<v[i].second<<"\n";
cout<<"\n-------------------------------\n";
}



int main()
{
    GO_FAST

    string s;
    cin>>s;
    lli n = s.length();
    for(int i=0;i<n;i++)
    {
        if(s[i] == 'm' || s[i] == 'w')
        {
            cout<<"0\n";
            return 0;
        }
    }


    lli dp[n+2] = {0};
    dp[1] = 1;
    dp[2] = 1;
    for(int i=3;i<n+2;i++)
            dp[i] = (dp[i-1] + dp[i-2])%1000000007;

    vector<pair<char,lli>> f = consecutive_freq(s);
    //pair_printer(f);
    lli ans = 1;
    for(auto i:f)
    {
        if(i.first == 'u' || i.first == 'n' )
            ans = (ans%mod)*((dp[i.second + 1])%mod);
    }
    cout<<ans%mod<<"\n";
    return 0;
}
