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
    lli l,r,n;
    cin>>n>>l>>r;
    for(int i=l;i<=r;i++)
    {
        if( (i^n) < n)
            cout<<"i = "<<i<<"\n";
    }
    return 0;
}
