#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;


bool is_prime(lli n)
{

    if(n==1)
        return 0;
    else
    {
        for(lli i=2; i<=sqrt(n); i++)
        {
            if(n%i == 0)
                return 0;
        }
    return 1;
    }

}

int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);

    int t;
    cin>>t;
    while(t)
    {
        lli a,b;
        cin>>a>>b;
        if( (a-b) == 1 && is_prime((a+b)) == 1)
            cout<<"YES\n";
        else
            cout<<"NO\n";
        t--;
    }
    return 0;
}
