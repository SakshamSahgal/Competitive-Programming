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
        lli sum= (n-1)*3;

        for(int i=1;i<=9;i+=2)
        {
            if( (sum + i)%9 != 0 && (sum + i)%3 == 0)
            {
                for(int j=1;j<=n-1;j++)
                    cout<<3;
                cout<<i<<"\n";
                break;
            }
        }



        t--;
    }
    return 0;
}
