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
    //GO_FAST

    lli n;
    cin>>n;
    string s;
    cin>>s;
    vector<char> v;
    string x;

    for(int i=0; i<n; i++)
    {
        if(v.size() == 0)
            v.push_back(s[i]);
        else if(v.size() == 1)
        {
            if(s[i] != v[0])
            {
                v.push_back(s[i]);
                x += v[0];
                x += v[1];
                v.clear();
            }
        }
    }
    cout<<s.size() - x.size()<<"\n";
    cout<<x<<"\n";

    return 0;
}
