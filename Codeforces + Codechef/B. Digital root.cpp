#include<iostream>
#include<algorithm>
#define usi unsigned short int
#define ui unsigned int
#define ulli unsigned long long int
using namespace std;
int main()
{
ios_base::sync_with_stdio(false);
cin.tie(NULL);
cout.tie(NULL);
usi n;
cin>>n;
long long int k;
long long int x;
while(n)
    {
    cin>>k>>x;
    cout<<x+(k-1)*9<<"\n";
    n--;
    }
return 0;
}
