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

lli sum=0;
vector<lli> ans;
int main()
{
    GO_FAST
    lli sum=0;
    for(int i=1;i<=35;i++)
    {
        lli x =pow(2,i) - 1;
        sum += ((x*(x+1))/2);
        //cout<<sum<<"\n";
        ans.push_back(sum);
    }


    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        auto ptr = lower_bound(ans.begin(),ans.end(),n);
        if(*ptr == n)
            cout<<ptr - ans.begin() + 1<<"\n";
        else
            cout<<ptr - ans.begin()<<"\n";
        t--;
    }
    return 0;
}
