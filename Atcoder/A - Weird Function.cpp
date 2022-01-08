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

lli f(lli t)
{
    return (t*t + 2*t + 3);
}

int main()
{
    //GO_FAST
    int t;
    cin>>t;
    cout<< f(f(f(t)+t)+f(f(t)))<<"\n";
    return 0;
}
