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
        lli a,b,x;
        cin>>a>>b>>x;
        if(a > b)
            swap(a,b);

        while(1)
        {
            if(a == 0 || b == 0)
            {
                cout<<"NO\n";
                break;
            }
            if(x > b)
            {
                cout<<"NO\n";
                break;
            }
            else
            {
                if ( x%a == b%a && x >= b%a )
                {
                    cout<<"YES\n";
                    break;
                }
                else
                {
                    b = b%a;
                    swap(a,b);
                }
            }


        }

        t--;
    }
    return 0;
}
