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
        lli a,b,c;
        cin>>a>>b>>c;
        if( ( (2*b > c) && (2*b - c)%a == 0) || ( (c+a)%(2*b) == 0 ) || ( (2*b > a) && (2*b - a)%c == 0 ) )
            cout<<"YES\n";
        else
            cout<<"NO\n";
        t--;
    }
    return 0;
}
