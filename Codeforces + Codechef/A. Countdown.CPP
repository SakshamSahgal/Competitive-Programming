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
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        int n;
        cin>>n;
        string s;
        cin>>s;
        lli sum=0;
         sum += (s[n-1] - 48);
        for(int i=0;i<n-1;i++)
        {
            if(s[i] != '0')
            sum += (s[i] - 48) + 1;
        }
        cout<<sum<<"\n";
        t--;
    }
    return 0;
}
