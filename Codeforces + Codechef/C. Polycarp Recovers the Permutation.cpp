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
        lli n;
        cin>>n;
        lli a[n];
        for(int i=0; i<n; i++)
            cin>>a[i];

        if(n == 1)
            cout<<a[0]<<"\n";
        else
        {
            if(a[0] == n || a[n-1] == n)
            {
                for(int i=n/2; i>=0; i--)
                    cout<<a[i]<<" ";
                for(int i=n-1; i > n/2 ; i --)
                    cout<<a[i]<<" ";
                cout<<"\n";
            }
            else
                cout<<"-1\n";
        }
        t--;
    }
    return 0;
}
