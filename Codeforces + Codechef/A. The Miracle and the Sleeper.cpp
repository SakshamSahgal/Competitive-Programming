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
        lli l,r;
        cin>>l>>r;
        if(r/2 + 1 >= l)
            cout<<r%(r/2 + 1)<<"\n";
        else
            cout<<r%l<<"\n";
        t--;
    }
    return 0;
}