#include<iostream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<algorithm>
#include<cmath>
#include<climits>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
    int t;
    cin>>t;
    while(t)
    {
        lli n,k;
        cin>>n>>k;

        if(n<=k)
        {
            if(k%n ==0)
                cout<<k/n<<"\n";
            else
                cout<<k/n + 1<<"\n";
        }
        else
        {
            lli x;
            if(n%k == 0)
             x = n/k;
            else
            x = n/k + 1;

            if( (x*k)%n == 0)
            cout<<(x*k)/n<<"\n";
            else
              cout<<(x*k)/n + 1<<"\n";

        }
        t--;
    }
    return 0;
}


