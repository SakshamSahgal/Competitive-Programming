#include<iostream>
#include<algorithm>
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
    usi t;
    cin>>t;
    while(t)
    {
        int n,k1,k2,w,b;
        cin>>n>>k1>>k2;
        cin>>w>>b;
        if( (( ( max(k1,k2) + min(k1,k2) )/2 )>= w) && ((( max((n-k1),(n-k2)) + min((n-k1),(n-k2)) )/2 ) >=b) )
        cout<<"YES\n";
        else
        cout<<"NO\n";

    t--;
    }

    return 0;
}

