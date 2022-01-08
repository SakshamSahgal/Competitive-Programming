
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
    map<pair<lli,lli>,lli> single;
    single[{1,2}] = 2;
    single[{1,2}] = 3;
    cout<<single[{1,2}]<<"\n";
    return 0;
}
