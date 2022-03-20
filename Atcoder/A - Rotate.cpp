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
    lli a;
    cin>>a;
    lli d1 = (a/100)%10;
    lli d2 = (a/10)%10;
    lli d3 = (a)%10;

    lli x = a + d2*100 + d3*10 + d1 + d3*100 + d1*10 + d2;
    cout<<x<<"\n";
    return 0;
}
