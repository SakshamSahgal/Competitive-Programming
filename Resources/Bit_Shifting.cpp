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

lli noz(lli x)
{
    lli c=0;
    for(lli j=0; j<=32; j++)
    {
        lli is_Set = (x>>j)%2;
        if(!is_Set)
            c++;
        else
            return c;
    }
    return c;
}

int main()
{
    //GO_FAST
    cout<<"8 me two ki power 0 wali bit = "<<(8>>0)%2<<"\n";
    cout<<"8 me two ki power 1 wali bit = "<<(8>>1)%2<<"\n";
    cout<<"8 me two ki power 2 wali bit = "<<(8>>2)%2<<"\n";
    cout<<"8 me two ki power 3 wali bit = "<<(8>>3)%2<<"\n";

    cout<<noz(6)<<"\n";
    return 0;
}

