#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
//ios_base::sync_with_stdio(false);
//cin.tie(NULL);
//cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        lli r,b,d;
        cin>>r>>b>>d;
        if( max(r,b) - (min(r,b)*(1+d)) > 0 )
            cout<<"NO\n";
        else
            cout<<"YES\n";
        t--;
    }

    return 0;
}
