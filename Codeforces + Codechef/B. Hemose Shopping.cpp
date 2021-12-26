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
        lli n,x;
        cin>>n>>x;
        lli a[n],b[n];

        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            b[i] = a[i];
        }

        if(x == n)
        {
            for(int i=0; i<n-1; i++)
            {
                if(a[i] > a[i+1])
                {
                    cout<<"NO\n";
                    goto k;
                }
            }
            cout<<"YES\n";
        }
        else
        {
            if(x == 1)
                cout<<"YES\n";
            else
            {
                lli maxx = n/2;
                if(x <= maxx)
                    cout<<"YES\n";
                else
                {
                    lli st = n-x;
                    lli ed = x-1;
                    sort(b,b+n);
                    for(int i=st;i<=ed;i++)
                        {
                            if(a[i] != b[i])
                            {
                                cout<<"NO\n";
                                goto k;
                            }
                        }

                    cout<<"YES\n";
                }
            }
        }
k:
        t--;
    }
    return 0;
}
