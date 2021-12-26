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
        lli a,b,c;
        cin>>a>>b>>c;

        cout<<max((lli)0,((max(b,c)-a) + 1))<<" "<<max((lli)0,((max(a,c)-b) + 1))<<" "<<max((lli)0,((max(a,b)-c) + 1))<<"\n";
        t--;
    }
    return 0;
}
