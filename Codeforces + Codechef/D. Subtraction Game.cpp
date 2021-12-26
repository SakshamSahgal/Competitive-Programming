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

bool is_prime(lli n)
{
    bool flag = 1;
    for(lli i = 2; i*i <= n; i++)
    {
        if (n % i == 0)
        {
            flag = 0;
            break;
        }
    }

    if (n <= 1)
        flag = 0;

    if (flag == 1)
        return 1;
    else
        return 0;

    return 0;
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

        lli c=0;
        for(lli i=n;i>=2;i--)
        {
            if(is_prime(i) == 1)
                break;
            else
                c++;
        }

        //cout<<c<<"\n";

        if(c%3 == 0)
            cout<<"NO\n";
        else
            cout<<"YES\n";

        t--;
    }
    return 0;
}
