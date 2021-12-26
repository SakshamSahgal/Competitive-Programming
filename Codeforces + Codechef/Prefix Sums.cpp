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

        if(n == 2)
            cout<<"NO\n";
        else
        {
            cout<<"YES\n";
            lli x[2][n/2];
            for(lli i=0,j=1; i<n/2; i+=2,j+=4)
            {
                x[0][i] = j;
                x[1][i] = j+1;
                x[1][i+1] = j+2;
                x[0][i+1] = j+3;
            }

            for(int i=0; i<n/2; i+=2)
            {
                swap(x[0][i],x[0][n/2-1 - i]);
                swap(x[1][i],x[1][n/2-1 - i]);
            }

            for(int i=0; i<n/2; i++)
                cout<<x[0][i]<<" ";
            cout<<"\n";
            for(int i=0; i<n/2; i++)
                cout<<x[1][i]<<" ";
            cout<<"\n";
        }

        t--;
    }
    return 0;
}
