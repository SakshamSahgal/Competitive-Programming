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
    lli n;
    cin>>n;
    lli s[n];
    lli t[n];
    lli sum=0;
    lli ans[n];
    lli min_index = 0;
    lli mini = INT_MAX;
    for(int i=0;i<n;i++)
            cin>>s[i];

    for(int i=0;i<n;i++)
    {
        cin>>t[i];
        if(t[i] < mini)
        {
           mini = t[i];
           min_index = i;
        }
    }


    for(int i=min_index;i<n;i++)
    {
        if(i == min_index)
             ans[i] = t[i];
        else
            ans[i] = min( t[i],ans[i-1] + s[i-1]);

    }

    for(int i=0;i<min_index;i++)
    {
        if(i == 0)
            ans[i] = min(t[i],ans[n-1] + s[n-1]);
        else
            ans[i] = min(t[i],ans[i-1] + s[i-1]);
    }

    for(int i=0;i<n;i++)
        cout<<ans[i]<<" ";
    return 0;
}


