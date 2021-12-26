#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
void Map_printer(map<char,int> x)
{
    cout<<"\n----------------------\n";
    for(auto i = x.begin(); i!=x.end(); i++)
        cout<<i->first<<" "<<i->second<<"\n";
    cout<<"\n----------------------\n";
}
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    map<char,int> available;
    map<char,int> req;
    string s;
    cin>>s;
    string r;
    cin>>r;
    for(int i=0; i<s.length(); i++)
        available[s[i]]++;

    for(int i=0; i<r.length(); i++)
        req[r[i]]++;

    //Map_printer(available);
    //Map_printer(req);

    int ans=0;

    for(auto i = req.begin();i != req.end();i++)
    {
        if(available[i->first] == 0)
        {
            cout<<"-1\n";
            return 0;
        }
        else
        {
            int ava = available[i->first];
            int re = i->second;
            if( re <= ava )
                ans+=re;
            else
                ans+=ava;
        }
    }
    cout<<ans<<"\n";
    return 0;
}


