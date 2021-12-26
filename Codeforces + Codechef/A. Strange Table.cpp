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
    lli t;
    cin>>t;
    while(t)
    {
        lli n,m,x;
        cin>>n>>m>>x;
        lli r;
        lli c;
        if(x%n == 0)
        {
            c = x/n;
            r = n;
        }
        else
        {
            c = x/n + 1;
            r = x%n;
        }

        //cout<<r<<" "<<c<<"\n";

        cout<<(r-1)*m + c<<"\n";
        t--;
    }
    return 0;
}
