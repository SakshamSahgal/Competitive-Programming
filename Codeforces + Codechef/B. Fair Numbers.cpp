#include<iostream>
#include<algorithm>
#include<vector>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
#define lli long long int
using namespace std;
bool digit_extractor(lli n)
{
    lli digit;
    lli temp = n;
    while(n!=0)
    {
        digit = n%10;
        n =n/10;
        if(digit!=0)
        {
            if(temp%digit!=0)
                return 0;
        }
    }
    return 1;
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
        for(lli i=n; i<=1000000000000000000; i++)
        {
            if(digit_extractor(i) == 1)
            {
                cout<<i<<"\n";
               goto j;
            }
        }
        j:
        t--;
    }


    return 0;
}
