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


lli sod(lli n)
{
    lli sum=0;
    while(n!= 0)
    {
        sum += n%10;
        n/=10;
    }
    return sum;
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
        lli n;
        cin>>n;
        while(__gcd(n,sod(n)) <= 1)
        {
            n++;
        }
        cout<<n<<"\n";
        t--;
    }
    return 0;
}


