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
        vector<int> a(n);
        vector<int> freq(n+1);
        int maxx = INT_MIN;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            freq[a[i]]++;
            maxx = max(a[i],maxx);
        }


        lli ans=0;

        for(int i=0;i<n;i++)
        {
            lli s = a[i];
            for(int j=i+1;j<n;j++)
            {
                s += a[j];

                if(s > maxx)
                    break;

                if(freq[s] > 0 )
                {
                    ans += freq[s];
                    freq[s] = 0;
                }

                if(ans == n)
                    break;
            }
        }
        cout<<ans<<"\n";
        t--;
    }
    return 0;
}
