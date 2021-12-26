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
        int na=0,nb=0,nc=0;

        for(int i=0;i<s.length();i++)
        {
            if(s[i] == 'A')
                na++;
            else if(s[i] == 'B')
                nb++;
            else
                nc++;
        }

        if(nb == na + nc)
            cout<<"YES\n";
        else
            cout<<"NO\n";

        t--;
    }
    return 0;
}
