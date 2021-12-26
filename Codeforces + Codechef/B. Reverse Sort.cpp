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
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        string s;
        cin>>s;
        string ss = s;
        sort(ss.begin(),ss.end());
        vector<lli> nm;
        lli found=0;
        for(int i=0; i<n; i++)
        {
            if(s[i] != ss[i])
            {
                found = 1;
                nm.push_back(i+1);
            }

        }

        if(found == 0)
            cout<<0<<"\n";
        else
        {
            cout<<1<<"\n";

            cout<<nm.size()<<" ";
            for(auto i:nm)
                cout<<i<<" ";
            cout<<"\n";
        }


        t--;
    }
    return 0;
}
