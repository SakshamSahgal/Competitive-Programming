#include<iostream>
#include<cstring>
#include<vector>
#include<set>
#include<map>
#include<deque>
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
        deque<lli> x;
        lli n;
        cin>>n;
        lli p[n];

        for(int i=0;i<n;i++)
        {
            cin>>p[i];

            if(x.size() == 0)
                x.push_front(p[i]);
            else
            {
                if(x.front() > p[i])
                    x.push_front(p[i]);
                else
                    x.push_back(p[i]);
            }
        }

        for(auto i:x)
            cout<<i<<" ";
    cout<<"\n";
        t--;
    }
    return 0;
}
