#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
#include<cmath>
#include<cstring>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        map<string,int> m;
        int c=0;
        string s;
        for(int i=1; i<=(3*n); i++)
        {
            cin>>s;
            cin>>c;
            m[s]+=c;
        }

        multimap<int,int> x;

        for(auto i = m.begin();i!=m.end();i++)
        {
            x.insert({i->second,i->second});
        }

        for(auto i = x.begin();i!=x.end();i++)
            cout<<i->second<<" ";

        cout<<"\n";
    }

    return 0;
}

