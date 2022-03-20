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
lli inf = 9e18;
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli c[n];
        set<lli> e;
        set<lli> o;
        lli ods = 0;
        lli es = 0;
        lli mini = LONG_LONG_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>c[i];
            if(i%2)
            {
                 o.insert(c[i]);
                 ods += c[i];
            }
            else
            {
                e.insert(c[i]);
                es += c[i];
            }
            if(i)
            {
                lli omin = (*o.begin());
                lli emin = (*e.begin());
                lli ans;
                if(i%2)
                    ans = ((n - i/2)*(omin) + (ods - omin) + (n - i/2)*(emin) + (es - emin));
                else
                    ans = ((n - i/2 + 1)*(omin) + (ods - omin) + (n - i/2)*(emin) + (es - emin));

                mini = min(mini,ans);
            }
        }
        cout<<mini<<"\n";
        t--;
    }
    return 0;
}
