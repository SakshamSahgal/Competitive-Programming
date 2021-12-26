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
        map<char,lli> cc;
        for(int i=0;i<n;i++)
            cc[s[i]]++;

        //for(auto i:cc)
            //cout<<i.first<<" "<<i.second<<"\n";
        for(auto i:cc)
        {
            for(int j=0;j<i.second;j++)
                cout<<i.first;

        }

    return 0;
}
