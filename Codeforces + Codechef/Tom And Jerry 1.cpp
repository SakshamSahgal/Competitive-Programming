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
    int a,b,c,d,k;
    cin>>a>>b>>c>>d>>k;
    int e = abs(a-c) + abs(b-d);
    if(k<e)
        cout<<"NO\n";
    else
    {
        if( (e%2 == 0 && k%2 == 0) || (e%2 == 1 && k%2 == 1) )
         cout<<"YES\n";
        else
        cout<<"NO\n";
    }
    t--;
    }

return 0;
}

