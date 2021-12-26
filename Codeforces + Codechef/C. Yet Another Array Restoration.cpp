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
        lli n,x,y;
        cin>>n>>x>>y;
        lli d = y-x;
        lli mini=INT_MAX;
        lli ans[n];
        for(int i=0; i<n; i++)
        {
            for(int j=i+1; j<n; j++)
            {
                lli a[n];
                //cout<<"for i = "<<i<<" j = "<<j<<"\n";
                int m = j-i-1;
                bool noo=0;
                if( (y-x)%(m+1) == 0 )
                {
                    int d = ((y-x)/(m+1));
                    int X=x;
                    int Y=y;
                    a[i] = X;
                    a[j] = Y;

                    for(int k=i-1; k>=0; k--)
                    {
                        if( X - d > 0 )
                        {
                            X-=d;
                            a[k] = X;
                        }
                        else
                            noo = 1;
                    }

                    if(noo == 1)
                       continue;

                    X=x;

                    for(int k=i+1; k<j; k++)
                    {
                        X+=d;
                        a[k] = X;
                    }

                    for(int k=j+1; k<n; k++)
                    {
                        Y+=d;
                        a[k] = Y;
                    }

                   // array_printer(a,n);
                   // cout<<"max element = "<<*max_element(a,a+n)<<"\n";
                    if( *max_element(a,a+n) < mini )
                    {
                        mini = *max_element(a,a+n);
                        for(int i=0;i<n;i++)
                            ans[i] = a[i];
                    }
                }
            }
        }

        for(auto i:ans)
            cout<<i<<" ";
        cout<<"\n";

        t--;
    }
    return 0;
}
