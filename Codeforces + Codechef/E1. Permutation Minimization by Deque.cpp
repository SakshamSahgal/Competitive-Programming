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
        lli n;
        cin>>n;
        lli p[n];
        vector<lli> vv;
        for(int i=0;i<n;i++)
            cin>>p[i];

        for(int i=0;i<n;i++)
            {
                if(vv.size() == 0)
                {
                    vv.push_back(p[i]);
                }
                else
                {
                    if(vv.size() == 1)
                    {
                        if(p[i] < vv[0])
                            vv.insert(vv.begin(),p[i]);
                        else
                            vv.push_back(p[i]);
                    }
                    else
                    {
                        if(p[i] < vv[0])
                            vv.insert(vv.begin(),p[i]);
                        else
                            vv.push_back(p[i]);
                    }
                }
            }

            for(auto i:vv)
                cout<<i<<" ";
        cout<<"\n";
        t--;
    }
    return 0;
}
