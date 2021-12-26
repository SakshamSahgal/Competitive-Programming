#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
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
    lli d,n;
    cin>>d>>n;
    int a[n];
    int ans=0;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i != n-1)
            ans += (d - a[i]);
    }
    cout<<ans<<"\n";
    return 0;
}


