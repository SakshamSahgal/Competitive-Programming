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
    set<lli> ans;
    for(int a=1;a<=250;a++)
        {
            for(int b=1;b<=250;b++)
            {
                lli xx = 4*a*b + 3*a + 3*b;
                //cout<<"a = "<<a<<" b = "<<b<<" area = "<<xx<<"\n";
                ans.insert(xx);
            }

        }

    lli n;
    cin>>n;
    lli c=n;
    for(int i=1;i<=n;i++)
    {
        lli xx;
        cin>>xx;
        if( ans.find(xx) != ans.end()  )
            c--;
    }
    cout<<c<<"\n";
    return 0;
}
