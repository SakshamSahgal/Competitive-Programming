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
    lli n,m;
    cin>>n>>m;
    lli mini=0;
    lli maxx=0;

    mini = max( (lli)0, n - 2*m);
    maxx = max((lli)0,n - 1 - m );
    cout<<mini<<" "<<maxx<<"\n";
    return 0;
}
