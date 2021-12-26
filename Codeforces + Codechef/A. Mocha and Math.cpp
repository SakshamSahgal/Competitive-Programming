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
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        lli a[n];
        lli ans=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            if(i==0)
            ans = a[0];
            else
             ans = a[i]&ans;
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}


