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
    lli n;
    cin>>n;
    vector<lli> t(n);
    vector<lli> uh;
    lli sum=0;
    for(int i=0;i<n;i++)
        cin>>t[i];
    sort(t.begin(),t.end());
    for(int i=0;i<n;i++)
    {
        if(sum > t[i])
            uh.push_back(t[i]);
        else
            sum += t[i];
    }
    cout<<(n-uh.size())<<"\n";
    return 0;
}
