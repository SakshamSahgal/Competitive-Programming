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
        lli a,b,c,x,y,z;
        cin>>a>>b>>c;
        cin>>x>>y>>z;
        lli maxx = INT_MIN;
        for(lli i=0;i<=20;i++)
            {
                for(lli j=0;j<=20;j++)
                    {
                        for(lli k=0;k<=20;k++)
                        {
                            if( i*a + j*b + k*c <= 240)
                            {
                                //cout<<x*i +y*j + z*k<<"\n";
                                maxx = max(maxx, (x*i +y*j + z*k) );
                            }

                        }
                    }
            }
        cout<<(lli)max((lli)0,maxx)<<"\n";
        t--;
    }
    return 0;
}
