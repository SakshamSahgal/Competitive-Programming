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
void array_printer(lli a[],lli n)
{
    cout<<"\n----------------\n";
    for(int i=0; i<n; i++)
        cout<<a[i]<<" ";
    cout<<"\n----------------\n";
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli h[n];
        lli b[n];
        for(int i=0; i<n; i++)
            cin>>h[i];

        for(int i=0; i<n; i++)
        {
            if(h[i] < i)
            {
                cout<<"NO\n";
                goto l;
            }
            else
            {
                if(i != n-1)
                {
                h[i+1] += (h[i] - i);
                h[i] = i;
                }

            }

            if(i > 0)
            {
                if(h[i] <= h[i-1])
                {
                    cout<<"NO\n";
                    goto l;
                }
            }

            //array_printer(h,n);
        }



        for(int i=0; i<n; i++)
            b[i] = h[i];

        sort(b,b+n);

        for(int i=0; i<n; i++)
        {
            if(b[i] != h[i])
            {
                cout<<"NO\n";
                goto l;
            }
        }

        cout<<"YES\n";

l:
        t--;
    }
    return 0;
}
