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


lli Smallest_div(lli n)
{
    for(lli i=2;(i*i)<=n;i++)
    {
        if(n%i == 0)
            return i;
    }

    return n;
}


int main()
{
    //GO_FAST
    lli p,y;
    cin>>p>>y;
    for(lli i=y;i>=p;i--)
        {
            if(Smallest_div(i) > p)
                {
                    cout<<i<<"\n";
                    return 0;
                }
        }
    cout<<"-1\n";
    return 0;
}
