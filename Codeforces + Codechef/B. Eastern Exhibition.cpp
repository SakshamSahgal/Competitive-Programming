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
        int n;
        cin>>n;
        vector<lli> xx;
        vector<lli> yy;
        for(int i=0; i<n; i++)
        {
            lli x,y;
            cin>>x>>y;
            xx.push_back(x);
            yy.push_back(y);
        }

        sort(xx.begin(),xx.end());
        sort(yy.begin(),yy.end());

        if(n%2 == 0)
            cout<< (xx[n/2] - xx[n/2 - 1] + 1)*(yy[n/2] - yy[n/2 - 1] + 1)<<"\n";
        else
            cout<<1<<"\n";
        t--;
    }
    return 0;
}
