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

bool is_equal(string s1,string s2)
{
    for(int i=0; i<s1.size(); i++)
        if(s1[i] != s2[i])
            return 0;
    return 1;
}
int main()
{
    string s,t;
    cin>>s>>t;

    if(s == t)
    {
        cout<<"Yes\n";
        return 0;
    }
    else
    {
        for(lli i=0; i<s.length()-1; i++)
        {
            string temp = s;

            swap(temp[i],temp[i+1]);

            if(is_equal(temp,t))
            {
                cout<<"Yes\n";
                return 0;
            }
        }
    }

    cout<<"No\n";
    return 0;
}
