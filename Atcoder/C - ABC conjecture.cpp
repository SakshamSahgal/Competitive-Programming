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

lli ans(lli n)
{
    lli gg = 0;
    for(int a=1; a<=n; a++)
    {
        for(int b=a; b<=n; b++)
        {
            for(int c=b; c<=n; c++)
            {
                cout<<"a = "<<a<<" b = "<<b<<" c = "<<c<<" ans = "<<( (a*b*c) <= n )<<"\n";
                if( ( (a*b*c) <= n ) )
                    gg++;
            }

        }
    }
    return gg;
}


void Debug()
{
    for(int i=1; i<=50; i++)
    {
        cout<<"\n-------------------------------------------\n";
        //cout<<"n = "<<i<<"\n";
        lli a = ans(i);
        //cout<<"for n = "<<i<<" ans = "<<a<<"\n";
        cout<<"("<<i<<","<<a<<")\n";
        cout<<"\n-------------------------------------------\n";
    }

}
int main()
{
    GO_FAST

    lli n;
    cin>>n;
    lli ans=0;
    for(lli a=1; a*a*a<=n; a++)
    {
        for(lli b=a; b*b<=(n/a); b++)
            ans += (n/(a*b)) - b + 1;
    }
    cout<<ans<<"\n";
    return 0;
}
