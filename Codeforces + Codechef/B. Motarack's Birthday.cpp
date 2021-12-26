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
    lli t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli b[n];
        vector<lli> v;
        for(lli i=0; i<n; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }


        for(int i=0; i<n; i++)
        {
            if(a[i] == -1)
            {
                if( i-1 >=0 && a[i-1] != -1)
                    v.push_back(a[i-1]);
                if(i+1 < n && a[i+1] != -1)
                    v.push_back(a[i+1]);
            }
        }
        lli mini = INT_MAX;
        lli maxx = INT_MIN;
        for(int i=0; i<v.size(); i++)
        {
            mini = min(v[i],mini);
            maxx = max(v[i],maxx);
        }

        lli k1 = (mini + maxx)/2;
        lli k2 = (mini + maxx)/2 + 1;
        lli m1 = INT_MIN,m2 = INT_MIN;
        for(int i=0;i<n;i++)
            {
                if(a[i] == -1)
                    a[i] = k1;
                if(b[i] == -1)
                    b[i] = k2;
            }

        for(int i=0;i<n-1;i++)
            {
                m1 = max(abs(a[i+1] - a[i]),m1);
                m2 = max(abs(b[i+1] - b[i]),m2);
            }

        if(m1 <= m2)
            cout<<m1<<" "<<k1<<"\n";
        else
            cout<<m2<<" "<<k2<<"\n";
        t--;
    }


    return 0;
}
