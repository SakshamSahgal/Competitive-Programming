#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define si short int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi t;
cin>>t;
while(t)
    {
    ulli n;
    cin>>n;
    int sum=0;
    while(n!=0)
        {
            sum += n%10;
            n = n/10;
        }
    cout<<sum<<"\n";
    t--;
    }
return 0;
}
