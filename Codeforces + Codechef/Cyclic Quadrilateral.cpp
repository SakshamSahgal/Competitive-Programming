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
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    if((a+c) == 180 && (b+d) == 180)
    cout<<"YES\n";
    else
    cout<<"NO\n";

    t--;
    }

return 0;
}

