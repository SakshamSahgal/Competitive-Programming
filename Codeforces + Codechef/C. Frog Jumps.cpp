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
        int n = s.length();
        vector<lli>index;
        index.push_back(0);
        for(int i=0;i<n;i++)
        {
            if(s[i] == 'R')
                index.push_back(i+1);
        }
        index.push_back(n+1);
        lli maxx = INT_MIN;
        for(int i=0;i<index.size()-1;i++)
            maxx = max( (index[i+1]-index[i]) , maxx );

        cout<<maxx<<"\n";
        t--;
    }
    return 0;
}
