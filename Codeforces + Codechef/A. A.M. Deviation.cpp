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
    int t;
    cin>>t;
    while(t)
    {
        lli a,b,c;
        cin>>a>>b>>c;

      if( (a + c - 2*b)%3 == 0 )
        cout<<0<<"\n";
      else
        cout<<1<<"\n";


        t--;
    }
    return 0;
}
