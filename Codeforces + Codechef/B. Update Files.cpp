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
void vector_printer( vector<lli> v)
{
    cout<<"\n------------------------\n";
    for(int i=0; i<v.size(); i++)
        cout<<v[i]<<" ";
    cout<<"\n------------------------\n";
}
int main()
{
    GO_FAST
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;
        if(n == 1)
            cout<<0<<"\n";
        else
        {
            lli tt = floor(log(k)/log(2) + 1);
            //cout<<tt<<"\n";
            lli maxx = pow(2,tt);
            //cout<<maxx<<"\n";
            if(maxx >= n)
            {
                if(maxx == n)
                    cout<<tt<<"\n";
                else
                    cout<<ceil(log(n)/log(2))<<"\n";
            }
            else
            {
                lli a = maxx;
                if( (n-a)%k == 0 )
                 cout<<tt + (n-a)/k<<"\n";
                else
                cout<<tt + (n-a)/k + 1<<"\n";

            }

        }
        t--;
    }
    return 0;
}
