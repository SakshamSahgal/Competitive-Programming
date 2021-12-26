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
    int n;
    cin>>n;
    vector<lli> vv;

    for(int i=0; i<n; i++)
    {
        lli x;
        cin>>x;
        vv.push_back(x);
    }

    sort(vv.begin(),vv.end());

    cout<<min(vv[vv.size()-2] - vv[0], vv[vv.size()-1] - vv[1] )<<"\n";
    return 0;
}
