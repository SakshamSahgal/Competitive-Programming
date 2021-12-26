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
    int a[4];
    for(int i=0;i<4;i++)
        cin>>a[i];

    int x = max(a[0],a[1]);
    int y = max(a[2],a[3]);
     sort(a,a+4);
    if( max(x,y) == a[3] && min(x,y) == a[2] )
        cout<<"YES\n";
    else
        cout<<"NO\n";

    t--;
    }

return 0;
}

