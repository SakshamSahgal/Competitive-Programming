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
    //GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n;
        cin>>n;
        lli a[n];
        lli s=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            s += a[i];
        }

        for(int i=0;i<n;i++)
            {
                lli rem = (s - a[i]);
                lli abs = a[i]*(n-1) + rem;
               // cout<<"rem = "<<rem<<" abs = "<<abs<<"\n";

                if( rem != 0 && abs <= 1000000000 )
                {
                    for(int j=0;j<n;j++)
                    {
                        if(j != i)
                            cout<<a[i]<<" ";
                        else
                            cout<<((-1)*(rem))<<" ";
                    }
                    break;
                }
            }
        cout<<"\n";
        t--;
    }
    return 0;
}
