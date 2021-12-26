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


bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;

    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i <= n; i = i + 6)
        if (n % i == 0 || n % (i + 2) == 0)
            return false;
    return true;
}

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
        lli sum=0;
        for(int i=0; i<n; i++)
        {
            cin>>a[i];
            sum += a[i];
        }

        if(isPrime(sum) == 0)
        {
            cout<<n<<"\n";
            for(int i=1;i<=n;i++)
                cout<<i<<" ";
            cout<<"\n";
        }
        else
        {
            cout<<n-1<<"\n";
            bool found=0;
            lli index=0;
            for(lli i=0;i<n;i++)
                {
                    if( a[i]%2 == 1)
                    {
                        found = 1;
                        index = i;
                        break;
                    }
                }
            for(int i=1;i<=n;i++)
            {
                if(i!= index+1)
                    cout<<i<<" ";
            }
            cout<<"\n";
        }
        t--;
    }
    return 0;
}
